// Fresh approach
// bc pagal ho kya, memset ke wajah se TLE de raha tha!

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
    if(i>n || j>m) return 0;
    if(k<0) return 0;
    if(i==n && j==m) {
        // if(grid[i][j]==1 && k<=0) return 0;
        // return 1;
        if(grid[i][j]==0 || k>0) return 1;
        return 0;
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    // choices
    int temp=k;
    if(grid[i][j]==1) k--;

    return dp[i][j][temp] = ((rec(i+1, j, k)%mod) + (rec(i, j+1, k)%mod))%mod;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) cin>>grid[i][j];
        }
        memset(dp, -1, sizeof(dp));
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         for(int l=0; l<=k; l++) dp[i][j][l]=-1;
        //     }
        // }

        cout << rec(1, 1, k) << "\n";
    }
    return 0;
}