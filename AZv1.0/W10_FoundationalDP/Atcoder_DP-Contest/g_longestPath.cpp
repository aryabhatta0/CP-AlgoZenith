#include <bits/stdc++.h>
using namespace std;

// dp[i]: longest path starting at i
// ans = max of dp

int n, m;
vector<vector<int>> adj;
vector<int> dp;

int rec(int i){
    if(dp[i]!=-1) return dp[i];
    if(adj[i].size()==0) return dp[i]=0;

    // paths
    int ans=0;
    for(auto v: adj[i]){
        ans = max(ans, rec(v));
    }

    return dp[i]=1+ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    dp.resize(n+1, -1);
    int ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, rec(i));
    }

    // print dp
    // cout << "dp: ";
    // for(int i=0; i<=n; i++) cout << dp[i] << " ";
    // cout << "\n";

    cout << ans << "\n";
    return 0;
}