#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The prb is related to finding connected component num of each node
// The idea is: Jitna dfs call, utna connected component

int n, m, q; 
vector<vector<int>> Adj;
vector<bool> vis;
vector<int> connectedComponent;
int cnt = 0;    // UID for each connected component
vector<int> connectedComponentSize;

void dfs(int u){
    vis[u] = true;
    connectedComponent[u] = cnt;
    connectedComponentSize[cnt]++;
    for(auto v : Adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    Adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vis.resize(n+1, false);
    connectedComponent.resize(n+1, 0);
    connectedComponentSize.resize(n+1, 0);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }

    while(q--){
        int flag; cin>>flag;
        if(flag == 1){
            int u; cin>>u;
            cout<<connectedComponentSize[connectedComponent[u]]<<"\n";
        } else {
            int u, v; cin>>u>>v;
            if(connectedComponent[u] == connectedComponent[v]){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }

    return 0;
}