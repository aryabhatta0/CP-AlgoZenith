// https://maang.in/problems/Building-Roads-192?resourceUrl=cs99-cp522-pl3547-rs192
#include <bits/stdc++.h>
using namespace std;
#define ll long long;

// Everything is about connected components!

int n, m; 
vector<vector<int>> Adj;
vector<bool> vis;

void dfs(int node){
    vis[node] = true;

    for(auto v: Adj[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    Adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vis.resize(n+1, false);

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }

    cout<<cnt-1<<"\n";
}