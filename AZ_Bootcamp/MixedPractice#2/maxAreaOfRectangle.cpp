#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Intuition:
 * You have to do it in n^3. 
 * So you can iterate over one of the dimension while precomputing sth for the other.
 
 * Imagine a histogram (along width here)!
 */

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));   // max width of rectangle ending at (i, j)
    int maxiArea=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]==1) {
                dp[i][j] = (j == 0 ? 1 : dp[i][j-1] + 1);

                // iterate over height
                int miniWidth=1e9;
                for(int h=i; h>=0; h--) {
                    // if(grid[h][j]==0) break;
                    miniWidth = min(miniWidth, dp[h][j]);
                    maxiArea = max(maxiArea, (i-h+1) * miniWidth);
                }
            }
        }
    }
    cout << maxiArea << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}