#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

/*
    // using resize gives RE
    // using memset gives TLE
*/

// vector<vector<int>> grid;
int grid[202][404];
int dp[202][202][404];

int n, m; 
int isValid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

// # of paths ending at (i,j) with k changes allowed
int rec(int i, int j, int k){
    // pruning
    if(k<0) return 0;
    if(!isValid(i, j)) return 0;

    // base case
    // if(i==0 && j==0) return 1;
    if(i==0 && j==0) {
        if(grid[i][j]==0 || k>0) return 1;
        return 0;
    }

    // cache check
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    // transition
    int ans = 0;
    if (grid[i][j]) {   // obstacle
        ans = (rec(i-1, j, k-1) + rec(i, j-1, k-1)) % mod;
    } else {
        ans = (rec(i-1, j, k) + rec(i, j-1, k)) % mod;
    }

    // save and return
    return dp[i][j][k] = ans%mod;
}

void solve() {
    int k; cin>>n>>m>>k;
    // grid.resize(n, vector<int>(m));      // using resize gives RE
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    // dp
    // memset(dp, -1, sizeof(dp));          // using memset gives TLE
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++){
                dp[i][j][l] = -1;
            }
        }
    }

    cout << rec(n-1, m-1, k) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}