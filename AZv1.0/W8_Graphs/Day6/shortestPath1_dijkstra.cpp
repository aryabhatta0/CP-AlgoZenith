// Standard Dijkstra Problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;   // {neighbour, dist}
const ll INF = 1e18;

int n, m;
vector<vector<state>> adj;
vector<ll> dist;
vector<bool> vis;

void dijkstra(int sc){
    priority_queue<pair<ll, int>> pq;   // dist, node
    pq.push({0, sc});
    dist[sc] = 0;

    while(!pq.empty()){
        int curr = pq.top().second; pq.pop();
        if(vis[curr]) continue;
        vis[curr] = true;

        for(auto v: adj[curr]){
            if(!vis[v.first]){
                if(dist[v.first] > dist[curr]+v.second){
                    dist[v.first] = dist[curr]+v.second;
                    pq.push({-dist[v.first], v.first});
                }
            }
        }
    }
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    dist.resize(n+1, INF);
    vis.resize(n+1, false);

    dijkstra(1);
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << "\n";
    return 0;
}