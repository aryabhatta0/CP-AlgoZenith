#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

/** Always put modulo ops under braces */

// optimally merge elements in an array => LR DP
int dp[505][505];
// dp[l][r] = min cost  to merge [i...j]

int a[505];
int pre[505];
int n; 

int rec(int l, int r){
    // base case
    if(l>=r) return 0;

    // cache check
    if(dp[l][r]!=-1) return dp[l][r];

    // transition
    int ans = 1e9;
    for(int mid=l; mid<r; mid++){
        /** Always put modulo ops under braces */
        ans = min(ans, rec(l, mid) + rec(mid+1, r) + (((pre[mid]-pre[l-1])%100) * ((pre[r]-pre[mid])%100)) );
        // int left_sum = (pre[mid] - (l > 1 ? pre[l-1] : 0)) % 100;
        // int right_sum = (pre[r] - pre[mid]) % 100;
        // ans = min(ans, rec(l, mid) + rec(mid + 1, r) + (left_sum * right_sum));
    }

    // save and return
    return dp[l][r]=ans;
}

void solve() {
    cin>>n;
    pre[0]=0;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(1, n) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}