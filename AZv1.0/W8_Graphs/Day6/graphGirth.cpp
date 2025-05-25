#include <bits/stdc++.h>
using namespace std;

// The question is to find the length of the shortest cycle in the graph
// Hint: Find possible shortest cycle for each node
// len_cycle = dist[u] + dist[v] + 1 for some edge (u, v) in the cycle

const int INF = 1e9;
int n, m;
vector<vector<int>> Adj;
vector<int> dist;
int girth = INT_MAX;

void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(auto v: Adj[curr]){
            if(dist[v]==INF){
                dist[v] = dist[curr]+1;
                q.push(v);
            }
            // if v not on the path from src to curr, then it is a cycle
            else if(dist[v]>=dist[curr]){
                girth = min(girth, dist[v]+dist[curr]+1);
                if(dist[v]==dist[curr]) return;     // optimization
            }
        }
    }
}

int main(){
    cin>>n>>m;
    Adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // dist.resize(n+1, INF);

    // we will find length of shortest cycle passing through each node, if any
    for(int i=1; i<=n; i++){
        dist.assign(n+1, INF);
        bfs(i);
    }

    // cout << "Girth is: " << girth << "\n";
    cout << (girth==INT_MAX ? -1 : girth) << "\n";
    return 0;
}