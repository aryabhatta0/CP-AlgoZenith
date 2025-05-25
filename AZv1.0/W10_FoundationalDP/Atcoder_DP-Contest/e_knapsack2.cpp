#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+1;

/** Old:
 * choices -> pick/skip -> recursion
 * dp[i][cap]: i...n bag left, cap restriction
 * return dp[0][cap]
*/

/** State Rotation: since return val is cheaper than state cap size
 * dp[i][val]: min weight req to get val, using i...n bags
 * ans => Iterate over all pos vals, and check if dp[0][val] <= W
*/

int n, cap;
vector<int> w(n), v(n);
int dp[110][100100];     // max val = v*n = 1e5

ll rec(int lev, int val){
    if(val<0) return INF;
    if(val==0) return 0;
    if(lev>=n) return INF;

    if(dp[lev][val]!=-1) return dp[lev][val];

    // pick
    ll w1 = INF;    /* INF initialization was crucial*/
    if(val>=v[lev]){
        w1 = w[lev];
        w1 += rec(lev+1, val-v[lev]);
    }

    // skip
    ll w2 = rec(lev+1, val);

    return dp[lev][val] = min(w1, w2);
}

void solve(){
    // can't do bS on val, as not all vals are possible, not monotone
    // int l=0, h=1e5;
    // int ans = -1;
    // while(l<=h){
    //     int mid = l + (h-l)/2;
    //     if(rec(0, mid) <= cap){
    //         ans = mid;
    //         l = mid+1;
    //     } else h = mid-1;
    // }

    int ans = -1;
    for(int i=0; i<=1e5; i++){
        if(rec(0, i)<=cap) ans = i;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>cap;
    w.resize(n), v.resize(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    memset(dp, -1, sizeof(dp));

    solve();
    return 0;
}