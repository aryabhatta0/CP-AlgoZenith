#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll INF = 1e18;

int n;
int c[100100];
string str[100100];
string revStr[100100];

ll dp[100100][2];
/**
 * dp[i][0] = min cost to sort i...n strings lexico without reversing ith string
 * dp[i][1] = min cost to sort i...n string lexico WITH ith string reversed
 * ans = max(dp[0][0], dp[0][1])
 * transition is based on trying out all possibilities
 
 * Thought process:: choices (reverse or not) => recursion => dp
*/

ll rec(int lev, int rev){
    if(lev==n) return INF;
    if(lev==n-1) return (rev==1 ? c[lev] : 0);

    if(dp[lev][rev]!=-1) return dp[lev][rev];

    string curr = str[lev];
    if(rev) curr = revStr[lev];

    // choices
    // donot reverse lev+1
    ll c1=INF;
    string next = str[lev+1];
    if(curr <= next) c1 = rec(lev+1, 0);    /* = was crucial */

    // reverse lev+1
    ll c2=INF;
    next = revStr[lev+1];
    if(curr <= next) c2 = rec(lev+1, 1);

    return dp[lev][rev] = min(c1, c2) + (rev==1 ? c[lev] : 0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>c[i];
        for(int i=0; i<n; i++) {
            cin>>str[i];
            revStr[i] = str[i];
            reverse(revStr[i].begin(), revStr[i].end());
        }

        memset(dp, -1, sizeof(dp));

        ll ans = min(rec(0,0), rec(0,1));
        if(ans==INF) cout << "-1\n";
        else cout << ans << "\n";
    }

    return 0;
}