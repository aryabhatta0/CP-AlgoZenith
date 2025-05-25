#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// dp array throws TLE, think why!
// Read Q: t<=1e5, it is guaranteed that the sum of n2 over all test cases does not exceed 1e6


// int dp[1001][1001];
vector<vector<int>> dp;
// dp[lev][dep] = number of strings in lev...n with 'depth' seen
int rec(int lev, int depth, string& str) {
    // base case
    if(depth<0) return 0;
    if(lev==str.size()) return depth==0;

    // cache check
    if(dp[lev][depth]!=-1) return dp[lev][depth];

    // transition
    ll ans=0;
    if(str[lev]=='?') {
        ans += rec(lev+1, depth-1, str);      // ')'
        ans += rec(lev+1, depth+1, str);    // '('
        ans %= mod;
    }
    else if(str[lev]=='(') ans = rec(lev+1, depth+1, str);
    else ans = rec(lev+1, depth-1, str);

    // save and return 
    return dp[lev][depth] = ans;
}

void solve(){
    string str; cin>>str;
    // return the number of ways to replace ‘?’ with ‘(‘ or ‘)’
    // memset(dp, -1, sizeof(dp));
    int n = str.size();
    dp.assign(n, vector<int>(n, -1));
    cout << rec(0, 0, str) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}