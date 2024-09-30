#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


/** NOTES:
 1. * Top-down: dp[i][j] = min health needed at start to reach (i,j)
    * v/s Buttom-up: dp[i][j] = min health needed at (i,j) to reach end

 ** The top-down does not work correctly because it fails to properly account for the health costs accumulated along the way in a forward manner.
 ** (i,j) -> (n,m) is the correct way!

 2. Binary Search:
    * You need min health needed at start to reach end without dying in the way
    * Can you find if you can reach end given starting energy? - check()
    * Use bS on minHealth
    * TC: O(n*m*logR)
 */


void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = max(1, 1 - grid[i][j]);
            } else {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]);
            }
        }
    }
    
    cout << dp[0][0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}