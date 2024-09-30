#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// P1: X, P2:Y
// P1: maximize (X-Y) => remove high value
// P2: minimize (X-Y) => remove high value => maximize (Y-X)
// Notice symmetry! That helps us to solve this with just dp[i][j]

// optimal X-Y value given X's chance first
ll dp[3010][3010];
// since the problem is symmetric, the next turn's X-Y would be Y-X for you.
// try out all possibilities, everyone will try to maximize their X-Y

int n;
int arr[3010];

ll rec(int l, int r){
    // base case
    if(l>r) return 0;

    // cache check
    if(dp[l][r]!=-1) return dp[l][r];

    // transition
    // try out all possibilities, everyone will try to maximize their X-Y
    ll ans = max(arr[l] - rec(l+1, r), arr[r] - rec(l, r-1));

    // save and return
    return dp[l][r] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}