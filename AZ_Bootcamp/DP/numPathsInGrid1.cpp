// https://maang.in/problems/Number-of-Paths-in-Grid-1-492?resourceUrl=cs117-cp540-pl3649-rs492&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// https://leetcode.com/problems/unique-paths-ii/description/
// Q: Given a grid of size n*m, you need to find the number of paths from (1, 1) to (n, m). 
// You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). 
// The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Trying out iterative DP this time 😎
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>arr[i][j];
    }

    if(arr[0][0]==1 || arr[n-1][m-1]==1) {
        cout<<"0\n";
        return;
    }

    // dp[i][j] = num of paths from (0,0) to (i,j)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0]=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;      // base case
            if(arr[i][j]==1) continue;      // obstacle
            if(i-1>=0) (dp[i][j] += dp[i-1][j]) %= mod;
            if(j-1>=0) (dp[i][j] += dp[i][j-1]) %= mod; 
        }
    }

    // cout << "dp: \n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    cout << dp[n-1][m-1] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}