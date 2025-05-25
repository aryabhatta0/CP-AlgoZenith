#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

using state = pair<int, int>;   // neighbour node, cost
const ll INF = 1e18;

void dijkstra(vector<vector<state>> &adj, int n, int sc=1){
    vector<ll> cost(n + 1, INF);
    vector<ll> minPriceRoutes(n + 1, 0);    // no. of min price routes to reach each node from source
    vector<ll> minFlight(n + 1, 0), maxFlight(n + 1, 0);   // min and max no. flight on minPriceRoutes

    priority_queue<pair<ll, int>> pq;   // cost, node
    cost[sc] = 0;
    pq.push({0, sc});
    minPriceRoutes[sc] = 1;
    minFlight[sc] = 0; maxFlight[sc] = 0;

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int curr = it.second; 
        if(-it.first > cost[curr]) continue;        // if cost of curr is already less than the cost in pq, then skip

        for(auto x: adj[curr]){
            if(cost[x.first] > cost[curr] + x.second){
                cost[x.first] = cost[curr] + x.second;
                pq.push({-cost[x.first], x.first});
                minPriceRoutes[x.first] = minPriceRoutes[curr];
                minFlight[x.first] = minFlight[curr] + 1;
                maxFlight[x.first] = maxFlight[curr] + 1;
            } else if(cost[x.first] == cost[curr] + x.second){
                // minPriceRoutes[x.first] = (minPriceRoutes[x.first] + minPriceRoutes[curr]) % mod;
                (minPriceRoutes[x.first] += minPriceRoutes[curr]) %= mod;
                minFlight[x.first] = min({minFlight[x.first], minFlight[curr] + 1, maxFlight[curr] + 1});
                maxFlight[x.first] = max({maxFlight[x.first], minFlight[curr] + 1, maxFlight[curr] + 1});
            }
        }
    }

    // cout << "cost: ";
    // for(int i = 1; i <= n; i++) cout << cost[i] << " "; 
    // cout << endl;

    if(cost[n] == INF) cout << "-1\n";
    else cout << cost[n] << " " << minPriceRoutes[n] << " " << minFlight[n] << " " << maxFlight[n] << "\n";
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<state>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(adj, n, 1);
    return 0;
}