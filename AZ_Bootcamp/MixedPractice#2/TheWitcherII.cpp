// https://leetcode.com/problems/dungeon-game/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Takeaway:
 * Add bottom dummy row and right dummy column to avoid out-of-bound checks. We fill it with infinities, except two ones - neighbors of the exit.
 
 * Intuition:
    dp[i][j] = min kitni energy de ki zinda pahuch jaye end tak
   Transition: (i,j) -> (i+1, j) or (i, j+1)
    Say dp[i+1][j] = x and grid[i][j] = y
    (i, j) par kitni energy de ki (i+1, j) par atleast x energy rahe => x-y
    x-y <= 0 hua toh, tab 1 de do!    (1-y will be > x then)
 */

/** Mistake: Pehle hum soche ke (0,0) se last tak jane mein kitna energy bachega max, uska opp ans
 * but bich mein bhi kahi 0 ho gaya toh??!
 
 * yeh sab kyu karna, sidha state mein hi store kar do kitna energy de min!!
 * Transition _/
 */

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin>>grid[i][j];
    }

    // dp[i][j] = min energey req at (i, j) last tak pahuchne ke liye
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            int next;   // next cell par kitni energy le ke pahuchna hai
            if(i==n-1 && j==m-1) {
                next = 1;    // exit karna hai with 1 score
            } else {
                next = min(dp[i+1][j], dp[i][j+1]);
            }

            // current par kitni energy de
            dp[i][j] = next - grid[i][j];
            if(dp[i][j] <= 0) dp[i][j] = 1;
        }
    }
    cout << dp[0][0] << "\n";
}

void solve2(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin>>grid[i][j];
    }

    // dp[i][j] = minimum health required to reach (n-1, m-1) from (i, j)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            if (i==n-1 && j==m-1) dp[i][j] = max(1, 1 - grid[i][j]);
            else dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]);
            // else {
            //     dp[i][j] = max(1, dp[i+1][j] - grid[i][j]);
            //     dp[i][j] = min(dp[i][j], max(1, dp[i][j+1] - grid[i][j]));
            // }
        }
    }
    cout << dp[0][0] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}