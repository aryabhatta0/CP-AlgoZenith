#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

// dp[i][j] : no. of ways in i...n-1 when u already have j open brackets
// u can only choose ')' if j>0
// u can't choose '(' if u have j open brackets and don't have enough characters to close them i.e, n-i < j
// ans = dp[0][0]

int n;
string str;

// ll dp[1001][1001];
vector<vector<ll>> dp;
/** Given: It is guaranteed that the sum of n2 over all test cases does not exceed 10^6 */
// This was the key. That makes us declare dp the way it is now & then resize each time.
// dp[1001][1001] would have given TLE.

ll rec(int lev, int open){
    if(open<0) return 0;
    if(lev==n){
        if(open==0) return 1;
        else return 0;
    }

    if(str[lev]=='(') return dp[lev][open]=rec(lev+1, open+1);
    else if(str[lev]==')') return dp[lev][open]=rec(lev+1, open-1);

    if(dp[lev][open]!=-1) return dp[lev][open];

    // choices
    // '(' :
    ll ans1=0;
    // if(n-lev-1 <= open+1) ans1 = rec(lev+1, open+1);
    ans1 = rec(lev+1, open+1);

    // ')' :
    ll ans2=0;
    if(open>0) ans2 = rec(lev+1, open-1);

    return dp[lev][open] = (ans1+ans2)%mod;
}

void printDP(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        // memset(dp, -1, sizeof(dp));
        cin>>str;
        n=str.size();

        dp.clear();
        dp.resize(n+1, vector<ll>(n+1, -1));
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=n; j++){
        //         dp[i][j]=-1;
        //     }
        // }
        // printDP();

        cout << rec(0, 0) << "\n";
        // printDP();
    }

    return 0;
}