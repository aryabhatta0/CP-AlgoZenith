#include <bits/stdc++.h>
using namespace std;
#define ll long long

/** Takeaway:
 * For Floyd-Warshall
   - create Adjacency Matrix
   - initialize dist[i][i] to 0

 * Use min() while taking input since two nodes can have multiple edges here!
 */

using state = pair<int, int>;
#define INF 1e18
void solve(){
    int n, m, q; cin>>n>>m>>q;

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for(int i=1; i<=n; i++) dist[i][i] = 0;

    int u, v, w;
    while(m--) {
        cin>>u>>v>>w;
        dist[u][v] = dist[v][u] = min(dist[u][v], (ll)w);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--) {
        int a, b; cin>>a>>b;
        cout << ((dist[a][b]==INF) ? -1 : dist[a][b]) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}