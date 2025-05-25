#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, m; cin>>n>>m;
    vector<pair<pair<int, int>, int>> edges;     // {{u,v}, w}
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({{u,v}, -w});
    }
    vector<ll> dist(n+1, 1e18);
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
        for (auto it : edges) {
            int u = it.first.first, v = it.first.second, w = it.second;
            dist[v] = min(dist[v], dist[u] + w);
        }   
    }

    // Relax once more to check for positive-weight cycle
    bool negCycle = false;
    for (auto it : edges) {
        int u = it.first.first, v = it.first.second, w = it.second;
        if (dist[u] + w < dist[v]) {
            // Positive-weight cycle found
            negCycle = true;
        }
    }

    if(negCycle) cout << "-1\n";
    else cout << -dist[n] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}