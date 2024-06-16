// https://maang.in/problems/BellmanFord-Revisited-209?resourceUrl=cs99-cp522-pl3595-rs209
// Bellman Ford Revisted
// To find max weight (longest) path from 1 to n in a graph with -ve weights
// Hint: Using -ve of weights to ultimately find minPath

/** Why |V|-1 times?
 * Atleast one node get its correct value in one iteration
 * 
 * coz in worst case, the closest edge to source will be at last
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;
const ll MIN = -1e18;
const ll INF = 1e18;

int n, m;
// vector<vector<state>> adj;
vector<pair<pair<int, int>, int>> edges;    // {u, v}, w

vector<ll> dist;    // min dist from sc

void bf(){
    dist.resize(n+1, INF);
    dist[1] = 0;

    /** Atleast one node get its correct value in one iteration */
    for(int i=0; i<n-1; i++){  // n-1 times
        // relax all edges
        for(auto e: edges){
            int u = e.first.first, v = e.first.second, w = e.second;
            dist[v] = min(dist[v], dist[u]+w);
        }
    }

    // check cycle
    bool negCycle = false;
    for(auto e: edges){         // relax once again
        int u = e.first.first, v = e.first.second, w = e.second;
        // if dist dec further, so -ve cycle
        if(dist[v] > dist[u]+w){    
            negCycle = true;
            break;
        }
    }

    if(negCycle) cout << "-1\n";
    else cout << -dist[n] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        // adj[a].push_back({b, c});
        edges.push_back({{a, b}, -c});
    }

    bf();
}