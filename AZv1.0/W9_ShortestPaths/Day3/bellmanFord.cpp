// Good Q: Bellman Ford
// To find max weight (longest) path from 1 to n in a graph with -ve weights
// Hint: Using -ve of weights in Bellman Ford

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;
const ll MIN = -1e18;
const ll INF = 1e18;

int n, m;
// vector<vector<state>> adj;
vector<pair<pair<int, int>, int>> edges;    // {u, v}, w

vector<ll> dist;    // max dist b/w 2 nodes

void bf(){
    dist.resize(n+1, INF);
    dist[1] = 0;

    for(int i=0; i<n-1; i++){  // n-1 times
        for(auto e: edges){
            int u = e.first.first, v = e.first.second, w = e.second;
            dist[v] = min(dist[v], dist[u]+w);
            // if(dist[u]!=MIN){
            //     dist[v] = max(dist[v], dist[u]+w);
            // }
        }
    }


    bool negCycle = false;
    for(auto e: edges){
        int u = e.first.first, v = e.first.second, w = e.second;
        if(dist[v] > dist[u]+w){    // if dist inc, magnitude still dec, so -ve cycle
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