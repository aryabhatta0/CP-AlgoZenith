// https://maang.in/problems/Shortest-Path-I-207?resourceUrl=cs99-cp522-pl3594-rs207

/** Correct way to make vis true in Dijkstra:
 * Push toh kayi baar hoga, par jab niklega wo final hoga, toh waha vis true karo
 */

/** Using !vis as a condition as well to update neighbours:
 * Works. Doesn't matter. Why?
 * 
 * pq (dijkstra) always follow minPath to any node
 * once it has taken out, it means no other min path could exist
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

using state = pair<ll, int>;    // cost, node
const ll INF=1e18;

void dijkstra(int sc, vector<vector<pair<int, int>>> adj, vector<ll>& dist, int n){
    priority_queue<state> pq;   // {-dist, node} - min heap
    vector<bool> visited(n+1, false);
    pq.push({0, sc});
    dist[sc]=0;
    // visited[1]=1;    // wrong

    while(!pq.empty()){
        int curr = pq.top().second; pq.pop();
        if(visited[curr]) continue;
        visited[curr]=1;

        for(auto v: adj[curr]){
            // we can check visited as well here, but not compulsorily
            // this includes vis check as well
            if(dist[v.first] > dist[curr] + v.second){
                dist[v.first] = dist[curr] + v.second;
                pq.push({-dist[v.first], v.first});
            }
        }
    }
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);     // stores node, len
    int a, b, c;
    while(m--){
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    // cal min dist to each nodes from 1
    vector<ll> dist(n+1, INF);
    dijkstra(1, adj, dist, n);

    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}