// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// max wt can be W cap
// maximize value

/**
 * choices -> pick/skip -> recursion
 * dp[i][cap]: max value among i...n item, with cap restriction
 * ans = dp[0][cap]
*/

/* Deciding states: dp[lev][?]
 * choice: pick/skip
 * if we pick one item, the cap to be taken dec
 * thus cap: another param of rec => dp[lev][cap]
 * we've to maximize value, so dp stores the max val in lev...n-1
*/

int n;
vector<int> w, v;

ll dp[101][101010];

ll rec(int lev, int cap){
    if(lev==n) return 0;
    if(cap<=0) return 0;
    if(dp[lev][cap]!=-1) return dp[lev][cap];

    // pick
    ll val1 = 0;
    if(cap>=w[lev]){
        val1 += v[lev];
        val1 += rec(lev+1, cap-w[lev]);
    }
    // skip
    ll val2 = rec(lev+1, cap);

    return dp[lev][cap] = max(val1, val2);
    
    // wrong - how? v[lev] hamesha hi add ho raha hai
    // return dp[lev][cap] = max(1LL*v[lev] + rec(lev+1, cap-w[lev]), rec(lev+1, cap));
}

void solve(){
    int cap;
    cin>>n>>cap;
    w.resize(n); v.resize(n);
    for(int i=0; i<n; i++)
        cin>>w[i]>>v[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, cap) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}