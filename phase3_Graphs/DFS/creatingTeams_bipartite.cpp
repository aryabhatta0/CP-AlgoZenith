// Bipertite Template
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The prb is about bipartite checking
// Idea is to color the nodes alternatively and check if any mismatch occurs

/** (sum-one) or (sum^one) gives other */

int n, m;
vector<vector<int>> Adj;
// vector<bool> vis;
vector<int> color;      // -1: not visited, 0: red, 1: blue
bool isBipartite = true;

void checkBipartite(int node, int clr){
    if(!isBipartite) return;
    color[node] = clr;

    for(auto v: Adj[node]){
        if(color[v]==-1){
            checkBipartite(v, clr^1);       // 1-clr v/s clr^1
        }
        else if(color[v]==clr){
            isBipartite = false;
            return;
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

    // vis.resize(n+1, false);
    color.resize(n+1, -1);
    for(int i=1; i<n; i++){
        if(!isBipartite) break;
        // if(!vis[i])
        if(color[i]==-1)
            checkBipartite(i, 0);
    }

    if(isBipartite) cout << "YES\n";
    else cout << "NO\n";
}