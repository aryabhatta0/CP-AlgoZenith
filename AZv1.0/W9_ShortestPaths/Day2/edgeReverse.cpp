#include <bits/stdc++.h>
using namespace std;

// HINT: 0-1 BFS 

using state = pair<int, int>;   // neighbour node, weight
const int INF = 1e9;
int bfs(vector<vector<state>> &adj, int n){
    queue<int> q;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(auto x: adj[curr]){
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
    vector<vector<state>> adj(n + 1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});   // reverse edge
    }

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