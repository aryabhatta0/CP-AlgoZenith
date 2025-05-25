#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** O(n^2) way:
 * For (i, j) look at squares in top, left and top left of it
 * and think how can you make the new square.
 */

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));   // max len of sqaure ending at (i, j)
    int maxLen=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]==1) {
                int top = (i-1>=0) ? dp[i-1][j] : 0;
                int left = (j-1>= 0) ? dp[i][j-1] : 0;
                int topLeft = (i-1>=0 && j-1>=0) ? dp[i-1][j-1] : 0;
                dp[i][j] = min({top, left, topLeft}) + 1;

                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    cout << maxLen*maxLen << "\n"; 
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}