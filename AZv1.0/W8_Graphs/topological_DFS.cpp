#include <bits/stdc++.h>
using namespace std;

// Finding topological ordering of DAG

int n, m;
vector<vector<int>> Adj;
vector<bool> vis;
vector<int> topo;

void dfs(int node){
    vis[node]=true;
    // topo.push_back(node);

    for(auto v: Adj[node]){
        if(!vis[v]){
            dfs(v);
        }
    }

    topo.push_back(node);
}

/*
5 5
1 2
1 3
2 4
3 4
2 5

*/

int main(){
    cin>>n>>m;
    Adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
    }

    vis.resize(n+1, false);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());
    cout << "Topological ordering is: ";
    for(auto x: topo){
        cout<<x<<" ";
    }
}