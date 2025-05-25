#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

// 2 choice -> recursion
// caching: dp[i]=> cost to reach N from i
// return dp[0]

int n;
vector<int> h;
vector<ll> dp;  // dp[i]: 

ll rec(int lev){
    if(lev>n-1) return INF;
    if(lev==n-1) return 0;
    if(dp[lev]!=-1) return dp[lev];

    ll c1 = rec(lev+1);
    c1 += abs(h[lev+1] - h[lev]);

    ll c2 = rec(lev+2);
    if(lev+2<n) c2 += abs(h[lev+2]-h[lev]);

    return dp[lev] = min(c1, c2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    h.resize(n);
    for(int i=0; i<n; i++) cin>>h[i];
    dp.resize(n, -1);
    cout << rec(0) << "\n";
}