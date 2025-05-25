#include <bits/stdc++.h>
using namespace std;
#define ll long long

/** Takeaway:
 * Read question patiently first - oneWay v/s twoWay road !
 * vis mein true kaha karte hai dhyan rakho!
 * state ko (int, int) banayega ya (ll, int) :)
 */

using state = pair<int, int>;   // {v, w}
#define INF 1e18
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<state>> adj(n+1);
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    vector<ll> dist(n+1, INF);
    vector<bool> vis(n+1, false);
    dist[1] = 0;

    priority_queue<pair<ll, int>> pq;       // {dist, node}
    pq.push({0, 1});

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int u = curr.second;

        if(vis[u]) continue;
        vis[u] = true;

        for(auto [v, w]: adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}