// https://maang.in/problems/Burn-them-All-618?resourceUrl=cs99-cp522-pl3594-rs618
// Dijkstra Application
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
ans = max(ans, (dist[u]+dist[v]+d)*5);

For a edge: u, v, d
time taken = v + (d - (v-u))/2 = (v+u+d)/2
*/

using state = pair<ll, int>;
const ll INF = 1e18;
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);    // neigh node, length
    int u, v, d;
    int max_edge=0;
    vector<pair<pair<int, int>, int>> edges;   // {{a,b}, c}
    while(m--){
        cin>>u>>v>>d;
        max_edge = max(max_edge, d);
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
        // edges.push_back(make_pair({u,v}, d))
        edges.push_back({{u,v}, d});
    }
    int sc; cin>>sc;

    // apply dijkstra to find distances from source
    priority_queue<state> pq;   // dist from A, node
    vector<ll> dist(n+1, INF);
    vector<bool> vis(n+1);
    
    dist[sc]=0;
    pq.push({0, sc});
    while(!pq.empty()){
        auto curr = pq.top().second;
        pq.pop();

        // push toh kayi baar honge, pop sirf ek baar karni hai
        if(vis[curr]) continue;
        vis[curr]=1;

        for(auto v: adj[curr]){
            // we could check !vis as well here, both works. why?
            // pq always follow minPath to any node
            // once it has taken out, it means no other min path could exist
            if(dist[v.first] > dist[curr] + v.second){
                dist[v.first] = dist[curr] + v.second;
                pq.push({-dist[v.first], v.first});
            }
        }
    }

    ll ans=0;
    for(auto it: edges){
        // time taken to burn u,v node and edge b/w them
        // v  + (d - (v-u))/2
        // (v + d + u)/2
        ans = max(ans, (dist[it.first.first] + dist[it.first.second] + it.second)*5);   // need 10T
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}