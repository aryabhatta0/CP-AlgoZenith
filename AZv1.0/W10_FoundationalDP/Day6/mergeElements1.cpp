#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

// dp[i][j]: cost of merging i...j to (pre[j]-pre[i-1])%100
// ans = dp[0][n-1]
// transition: min of:
// dp(i, mid) + dp(mid+1, j) + (sum(i,mid)*sum(mid+1,r))

// i & dp(i+1, j) ,, dp(i, i+1) & dp(i+2, j) ,, dp(i, i+2) & dp(i+3, j) ,, ...

int n;
vector<int> a;
// key obsv. was merging the array will give same result no matter how u do it.
// only the cost changes due to modulo
vector<int> pre;   
ll dp[505][505];

int sum(int l, int r){
    if(l==0) return pre[r];
    if(l==r) return a[l];
    return pre[r] - pre[l-1];
}

ll rec(int l, int r){
    if(l==r) return 0;
    if(l>r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    ll res=INF;
    for(int mid=l; mid<r; mid++){
        // merge l...mid & mid+1...r
        ll cost = rec(l, mid) + rec(mid+1, r);

        // merge this two merged
        /** always put modulo ops in bracket */
        cost += ((sum(l,mid)%100) * (sum(mid+1, r)%100));
        res = min(res, cost);
    }
    return dp[l][r] = res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    a.resize(n); pre.resize(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(i==0) pre[0]=a[0];
        else pre[i]=pre[i-1]+a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << "\n";
    return 0;

}