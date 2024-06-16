// https://maang.in/problems/Jump-Game-897?resourceUrl=cs99-cp522-pl3599-rs897

/* Concept of supernodes:
 * It reduces no. of edges from mC2 to 2m for every m same val in dijkstra !
 * Remember the time complexity of Dijkstra is (n+m)logn
 * 
 * Usage:
 * We create 1 supernode for a group same value and connect it to each of them so that incoming cost is a & outgoing 0 or vice-versa
 * giving the effective cost b/w any 2 node as a only
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;   // node, cost
const ll INF = 1e18;

void dijkstra(int src, vector<vector<state>> &adj, int n){
    vector<ll> dist(2*n+1, INF);
    vector<bool> vis(2*n+1, false);
    priority_queue<pair<ll, int>> pq;   // -dist, node
    pq.push({0, src});
    dist[src]=0;

    while(!pq.empty()){
        int curr = pq.top().second; pq.pop();
        if(vis[curr]) continue;
        vis[curr] = true;

        for(auto it: adj[curr]){
            if(dist[it.first] > dist[curr] + it.second){
                dist[it.first] = dist[curr] + it.second;
                pq.push({-dist[it.first], it.first});
            }
        }
    }

    for(int i=0; i<n; i++) cout << dist[i] << " ";
    cout << "\n";
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b; cin>>n>>a>>b;
    // vector<int> vec(n);
    vector<vector<state>> adj(2*n+1);   // max 2*n nodes after adding supernodes
    map<int, vector<int>> mp;   // val, indices with same value
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        mp[temp].push_back(i);
        if(i-1>=0) adj[i].push_back({i-1, b});
        if(i+1<n) adj[i].push_back({i+1, b});
    }

    // add super nodes for same values
    // reduces no. of edges from mC2 to 2m for every m same val in dijkstra !
    int super = n;  
    for(auto it: mp){
        if(it.second.size()>1){
            for(auto i: it.second){
                adj[super].push_back({i, a});
                adj[i].push_back({super, 0});
            }
            super++;
        }
    }

    int src; cin>>src;
    src--;

    dijkstra(src, adj, n);
    return 0;
}