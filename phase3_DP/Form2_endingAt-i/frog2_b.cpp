// https://atcoder.jp/contests/dp/tasks/dp_b
// Frog jump from 1...n with k choices (i+1...i+k) and a cost for each jump

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int INF = 1e9;

int n, k;
vector<int> height;

// dp[lev] = min cost to reach N-1 from lev
// ans = dp[0]
// transition: i+1, i+2, ..., i+k choices

int dp[100100];

int rec(int lev){
    if(lev==n) return INF;
    if(lev==n-1) return 0;      // 
    if(dp[lev]!=-1) return dp[lev];

    // choices
    int ans=INF;
    for(int i=1; i<=k; i++){
        if(lev+i >= n) break;
        // ans = min(ans, abs(height[lev+i]-height[lev]) + rec(lev+i));

        int c = rec(lev+i);
        c += abs(height[lev+i]-height[lev]);
        ans = min(ans, c);
    }
    return dp[lev] = ans;
}

void solve(){
    cin>>n>>k;
    height.resize(n);
    for(int i=0; i<n; i++) cin>>height[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0) << "\n";
}

int32_t main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}