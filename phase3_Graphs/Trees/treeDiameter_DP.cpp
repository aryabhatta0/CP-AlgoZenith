#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;

// length of longest path starting at 'start'
// dp[i] =max(dp[i], 1+dp[v]) for every neigh v
int getDiameter(int start){
    if(dp[start] != -1) return dp[start];
    
    int ans = 1;
    for(auto v: adj[start]){
        ans = max(ans, 1+getDiameter(v));
    }
    
    return dp[start] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dp.resize(n+1, -1);
    int ans=0;
    for(int i=1; i<=n; i++){
    	ans = max(ans, getDiameter(i));
        // cout << "i: " << i << " ans: " << ans << "\n";	// debug
    }
    
    cout << ans << "\n";
}