#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int n, m;
int a[1001][1001];
ll dp[1001][1001];

// dp[i][j] = max sum path from (i,j) to (n,m)
// ans = dp[1][1]

// (1,1) -> (n,m) are valid
bool isValid(int i, int j){
    return (i>=1) && (j>=1) && (i<=n) && (j<=m);
}

ll rec(int i, int j){
    if(!isValid(i,j)) return -INF;
    if(i==n && j==m) return a[n][m];

    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = a[i][j] + max(rec(i+1, j), rec(i, j+1));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) cin>>a[i][j];
        }
        memset(dp, -1, sizeof(dp));
        cout << rec(1, 1) << "\n";
    }
    return 0;
}