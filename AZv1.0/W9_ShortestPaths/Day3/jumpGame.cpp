
// Hint: Concept of supernodes
// to reduce time complexity of dijkstra implemented here

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;
const ll INF = 1e18;

/*
10 1 2                                
1 2 1 1 2 3 2 3 2 1                                  
1
*/

void dijkstra(int src, vector<vector<state>> &adj, int n){
    vector<ll> dist(2*n+1, INF);
    vector<bool> vis(2*n+1, false);
    priority_queue<pair<ll, int>> pq;   // dist, node
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
    map<int, vector<int>> mp;   // val, indices
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        mp[temp].push_back(i);
        if(i-1>=0) adj[i].push_back({i-1, b});
        if(i+1<n) adj[i].push_back({i+1, b});
    }

    // supernodes for same values
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

    // for(auto i: mp){
    //     for(auto j: i.second){
    //         for(auto k: i.second){
    //             if(j!=k) adj[j].push_back({k, a});
    //         }
    //     }
    // }

    int src; cin>>src;
    src--;

    dijkstra(src, adj, n);
    return 0;
}