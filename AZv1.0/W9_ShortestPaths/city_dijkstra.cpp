#include <bits/stdc++.h>
using namespace std;
#define ll long long

using ii = pair<int, int>;
using state = pair<int, int>;   // {node, fuel}

int n, m;
int k;  // petrol capacity
vector<vector<pair<int, ii>>> graph;    // stores its neighbouring nodes along with the properties of the edge - {node, {petrol, distance}}
int cost[1001];   // cost of each node

// creating vector of vectors each time is little overhead
int dist[1001][1001];   // stores the minimum distance to reach a node with a given amount of petrol
// in dijkstra, we can't overwrite visited nodes with distance just like bfs
int vis[1001][1001];    // stores if a node is visited with a given amount of petrol

// Doubt: What if we simply update if better distance is found, instead of checking if visited or not??
// TLE, okayy. Think again.
// The thing is: Ki same node ke multiple dists agar pq mein store ho gaye, toh hame ek hi process karna hai!! That's why vis imp.
// Yeh BFS k insertion dekh ke thought aaya

void dijkstra(state sc){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dist[i][j] = INT_MAX;
            vis[i][j] = 0;
        }
    }

    // We'll be pushing each new possible states to the pq
    priority_queue<pair<int, state>> pq;    // {-distance, state}
    dist[sc.first][sc.second] = 0;
    pq.push({0, sc});

    while(!pq.empty()){
        auto val = pq.top(); pq.pop();
        int curr_dist = -val.first;
        state curr_state = val.second;

        // check visited : 2nd baar same node pq se nikal rha hai, toh skip
        // Doubt: Guarantee hai kya ki 2nd time greater distance hi hoga?? Haan toh dist hi check kar lo, why make vis array
        if(vis[curr_state.first][curr_state.second]) continue;
        vis[curr_state.first][curr_state.second] = 1;   // fixing the smallest val
        // -- very crucial (using vis) - gets TLE, if not used


        // try and go to neighbours
        for(auto v: graph[curr_state.first]){
            // pre-condition
            if(curr_state.second >= v.second.first){  // if we have enough petrol 

                // relax dijkstra
                // if(dist[v.first][curr_state.second - v.second.first] > curr_dist + (0)){
                if(!vis[v.first][curr_state.second - v.second.first] && dist[v.first][curr_state.second - v.second.first] > curr_dist + (0)){
                    dist[v.first][curr_state.second - v.second.first] = curr_dist + (0);
                    pq.push({-dist[v.first][curr_state.second - v.second.first], {v.first, curr_state.second - v.second.first}});
                }
            }
        }

        // refill petrol
        // DOUBT: 1litre filling hi kyu?

        // pre-condition
        if(curr_state.second < k){  // enough petrol
            // relax dijkstra
            if(!vis[curr_state.first][curr_state.second + 1] && dist[curr_state.first][curr_state.second + 1] > curr_dist + cost[curr_state.first]){
                dist[curr_state.first][curr_state.second + 1] = curr_dist + cost[curr_state.first];
                pq.push({-dist[curr_state.first][curr_state.second + 1], {curr_state.first, curr_state.second + 1}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;

    // cost.resize(n+1);
    for(int i=0; i<=n; i++) cin>>cost[i];

    graph.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v, petrol, distance;
        cin>>u>>v>>petrol>>distance;
        graph[u].push_back({v, {petrol, distance}});
        graph[v].push_back({u, {petrol, distance}});
    }

    // To find the shortest path to reach end
    // Cost of an edge = +ve => Dijkstra 

    int st_node = 1, en_node=n;

    state sc = {st_node, 0};    // starting with 0 petrol
    dijkstra(sc);

    cout << dist[en_node][0] << "\n";
    return 0;
}