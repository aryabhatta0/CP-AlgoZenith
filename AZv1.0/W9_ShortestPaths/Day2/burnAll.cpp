#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**

ans = max(ans, (dist[u]+dist[v]+d)*5);

For a edge: u, v, d
time taken = v + (d - (v-u))/2 = (v+u+d)/2

*/

using state = pair<int, int>;   // neighbour node, length
const ll INF = 1e18;

int n, m;
vector<vector<state>> adj;
vector<ll> dist;
vector<bool> vis;
vector<pair<pair<int, int>, int>> edges;    // {u, v}, d

void dijkstra(int sc){
    dist.resize(n + 1, INF);
    dist[sc]=0;
    vis.resize(n+1, false);

    // priority_queue<state> pq;   // dist, node
    priority_queue<pair<ll, int>> pq;   // dist, node
    pq.push({0, sc});

    while(!pq.empty()){
        int curr = pq.top().second; pq.pop();
        if(vis[curr]) continue;
        vis[curr] = true;

        for(auto x : adj[curr]){
            if(!vis[x.first] && dist[x.first]>dist[curr]+x.second){
                dist[x.first] = dist[curr]+x.second;
                pq.push({-dist[x.first], x.first});
            }
        }
    }

    // print dist
    // cout << "dist: ";
    // for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    // cout << endl;

    // dist[0]=0;
    // cout << 10 * (*max_element(dist.begin()+1, dist.end())) << "\n";

    ll ans = 0;
    for(auto x : edges){
        int u = x.first.first, v = x.first.second, d = x.second;
        // if(abs(dist[u]-dist[v])==d && ans < (min(dist[u], dist[v])+d)*10) {
        //     ans+=d*10;
        // }
        // else{
        //     d-=(max(dist[u], dist[v])-min(dist[u], dist[v]));
        //     // ans+=(d/2)*10;
        //     ans+=(d*5);

        // }

        ans = max(ans, (dist[u]+dist[v]+d)*5);
        // cout << "edge: " << u << "-" << v << " => ans=" << ans << "\n"; 
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    adj.resize(n + 1);
    for(int i=0; i<m; i++){
        int u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
        edges.push_back({{u, v}, d});
    }
    int a; cin>>a;

    dijkstra(a);
    return 0;
}