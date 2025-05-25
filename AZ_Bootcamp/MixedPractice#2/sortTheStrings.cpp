// https://maang.in/problems/Sort-the-strings-168?resourceUrl=cs117-cp540-pl3650-rs168&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// return if s1 is lexico higher or not
bool check(string s1, int f1, string s2, int f2) {
    if(f1) reverse(s1.begin(), s1.end());
    if(f2) reverse(s2.begin(), s2.end());
    return s1 >= s2;
}

int n;
vector<vector<ll>> dp;
// dp[lev][last: 0/1] = min cost in lev...n given last string is sorted or not
// 0: no reverse, 1: reverse, 2: initial
ll rec(int lev, int last, vector<int>& cost, vector<string>& str) {
    // base case
    if(lev==n) return 0;

    // cache check
    if(dp[lev][last]!=-1) return dp[lev][last];

    // transition - try out both possibility
    ll ans=1e18;
    // reverse
    if(lev-1<0 || check(str[lev], 1, str[lev-1], last)) {
        ans = min(ans, rec(lev+1, 1, cost, str) + cost[lev]);
    }
    // don't reverse
    if(lev-1<0 || check(str[lev], 0, str[lev-1], last)) {
        ans = min(ans, rec(lev+1, 0, cost, str));
    }

    // save and return
    return dp[lev][last] = ans;
}

void solve(){
    cin>>n;
    vector<int> cost(n);
    for(int i=0; i<n; i++) cin>>cost[i];
    vector<string> str(n);
    for(int i=0; i<n; i++) cin>>str[i];
    
    dp.assign(n, vector<ll>(3, -1));
    ll ans = rec(0, 2, cost, str);
    cout << ((ans==1e18) ? -1 : ans) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}