#include <bits/stdc++.h>
using namespace std;

// HINT: 0-1 BFS 

using state = pair<int, int>;   // neighbour node, weight
const int INF = 1e9;
int bfs(vector<vector<state>> &adj, int n){
    queue<int> q;
    vector<int> dist(n + 1, INF);   // min dist from source=1
    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(auto x: adj[curr]){
            // each node has to be traversed just once ? NO!
            // so can't just check if it's INF
            if(dist[x.first] > dist[curr]+x.second){
                dist[x.first] = dist[curr] + x.second;
                q.push(x.first);
            }
        }
    }

    return dist[n];
}


void solve(){
    int n, m;
    cin>>n>>m;
    // adj stores {neigh, cost} for each node
    // cost could be either 0 or 1 (1 means reversing the edge)
    vector<vector<state>> adj(n + 1);   
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});   // reverse edge
    }

    // now simply find min cost path to goal=n
    int res = bfs(adj, n);
    if(res==INF) cout << "-1\n";
    else cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}