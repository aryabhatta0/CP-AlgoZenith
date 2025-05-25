#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

// 2 choice -> recursion
// caching: dp[i]=> cost to reach N from i
// return dp[0]

int n, k;
vector<int> h;
vector<ll> dp;

ll rec(int lev){
    if(lev>n-1) return INF;
    if(lev==n-1) return 0;
    if(dp[lev]!=-1) return dp[lev];

    ll ans=INF;
    for(int i=1; i<=k; i++){
        if(lev+i>=n) break;

        ll c = rec(lev+i);
        c += abs(h[lev+i]-h[lev]);
        ans = min(ans, c);
    }

    return dp[lev] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    h.resize(n);
    for(int i=0; i<n; i++) cin>>h[i];
    dp.resize(n, -1);
    cout << rec(0) << "\n";
}