#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n;
int dp[1001001][4];

// dp[lev][match] = number of ways to fill 0...lev so that match chars are matched (seen before)
// ans = dp[n-1][0]
// transition: state diagram

// DOUBT: Lil doubt in intuition in going 0...lev than lev...n-1 for caching across queries ??

ll rec(int lev, int match){
    if(lev<0) return 1;
    // if(lev==n) return 1;

    if(dp[lev][match]!=-1) return dp[lev][match];

    // 2 choices : 0/1

    if(match==0) return dp[lev][match] = (rec(lev-1, 1) + rec(lev-1, 0))%mod;
    else if(match==1) return dp[lev][match] = (rec(lev-1, 1) + rec(lev-1, 2))%mod;
    else if(match==2) return dp[lev][match] = (rec(lev-1, 3) + rec(lev-1, 0))%mod;
    else return dp[lev][match] = 0 + rec(lev-1, 2);

    // Caching across queries not allowed:
    // if(match==0) return dp[lev][match] = (rec(lev+1, 1) + rec(lev+1, 0))%mod;
    // else if(match==1) return dp[lev][match] = (rec(lev+1, 1) + rec(lev+1, 2))%mod;
    // else if(match==2) return dp[lev][match] = (rec(lev+1, 3) + rec(lev+1, 0))%mod;
    // else return dp[lev][match] = 0 + rec(lev+1, 2);
    
    // WRONG:
    // if(match==0) return dp[lev][match] = (rec(lev-1, 0) + rec(lev-1, 2))%mod;   // 1 , 1
    // else if(match==1) return dp[lev][match] = (rec(lev-1, 1) + rec(lev-1, 0))%mod;      // 0 , 0
    // else if(match==2) return dp[lev][match] = (rec(lev-1, 1) + rec(lev-1, 3))%mod;      // 1, 1
    // else return dp[lev][match] = (rec(lev-1, 2) + 0)%mod;   // 1, 0
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin>>n;
        cout << rec(n-1, 0) << "\n";
        // cout << rec(n-1, 0) + rec(n-1, 1) + rec(n-1, 2) + rec(n-1, 3) << "\n";       // ??
        // cout << rec(0, 0) << "\n";
    }
    return 0;
}