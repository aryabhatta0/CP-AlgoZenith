#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n, m, k;
int grid[202][202];

// dp[i][j][k] = num paths from (i,j) to (n,m) with k change left
// ans = dp[1][1][k]
ll dp[202][202][404];

ll rec(int i, int j, int k){
    if(grid[i][j]==1) k--;  // khud obs ho toh

    if(k<0) return 0;
    if(i==n && j==m) {
        if(grid[i][j]==1 && k<=0) return 0;
        return 1;
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    // choices
    // right
    ll cnt1=0;
    if(j+1<=m){
        // if(grid[i][j+1]==1) cnt1 = rec(i, j+1, k-1);
        // else cnt1 = rec(i, j+1, k);
        cnt1 = rec(i, j+1, k);
    }

    // down
    ll cnt2=0;
    if(i+1<=n){
        // if(grid[i+1][j]==1) cnt2 = rec(i+1, j, k-1);
        // else cnt2 = rec(i+1, j, k);
        cnt2 = rec(i+1, j, k);
    }

    // return dp[i][j][k] = (cnt1+cnt2)%mod;
    return dp[i][j][k] = (cnt1%mod+cnt2%mod)%mod;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m>>k;
        // grid.resize(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) cin>>grid[i][j];
        }
        memset(dp, -1, sizeof(dp));
        cout << (rec(1, 1, k)%mod) << "\n";
    }
    return 0;
}