#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Shortest Path Formulation:
 * Think of the state of graph based on whatever matters/varying    - {node, fuel_left} here
 * {-cost, state} to be added to pq     - for dijkstra
 * 
 * Explore implicit graph based on pre-condition check
 * i.e, (refilling upto cap) and/or (moving to neigh node if we have enough petrol) !

 * cost[10101][101] - mostly like a DP
 * we'll be going through all the states i.e, min cost to reach all the node with petrol 1.....100
 * look at graph transition in notes
 * vis _/ : so a state won't be explored again once it gets their best cost!
*/

using state = pair<int, int>;
const int INF = 1e9;
// check constraints
int cost[10101][101];   // cost to reach ith node with j petrol left
bool vis[10101][101];   // dijkstra always have a vis array that ensures popping just once

void solve(){
    int n, m; cin>>n; cin>>m;
    vector<vector<state>> adj(n+1);  // {v,d}
    while(m--){
        int u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    vector<int> petrol(n+1);     // per l petrol cost
    for(int i=1; i<=n; i++) cin>>petrol[i];

    int st, en, cap;
    cin>>st>>en>>cap;

    // state of graph: {node, fuel left}
    state sc = {st, 0};

    // memset doesn't work with INF
    // memset(cost, INF, sizeof(cost));        
    // memset(vis, 0, sizeof(vis));
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=cap; j++){
            cost[i][j] = INF;       // cost defined globally
            vis[i][j] = 0;          // vis needed in dijkstra
        }
    }

    ///////////////////////// dijkstra /////////////////////////////////

    priority_queue<pair<int, state>> pq;    // {-cost, {node, fuel left}}
    pq.push({0, sc});
    cost[sc.first][sc.second]=0;

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        int curr_cost = -curr.first;
        int curr_node = curr.second.first;
        int fuel_left = curr.second.second;
        // cout << "popping state: " << curr_node << " fuel=" << fuel_left << " cost incurr=" << curr_cost << "\n";
        
        // check visited    - very imp, otherwise TLE.
        if(vis[curr_node][fuel_left]) continue;
        vis[curr_node][fuel_left] = 1;

        // iterate through implicit neighbours
        for(auto v: adj[curr_node]){         // v: {node, dist}
            // if we have enough petrol - pre-condition
            if(fuel_left >= v.second){
                // check next node  - doesn't take any extra cost
                if(cost[v.first][fuel_left-v.second] > cost[curr_node][fuel_left] + (0)){
                    cost[v.first][fuel_left-v.second] = cost[curr_node][fuel_left];
                    pq.push({-cost[v.first][fuel_left-v.second], {v.first, fuel_left-v.second}});
                }
            }
        }

        // refill more petrol   - max lim is cap: pre-condition
        if(fuel_left < cap){
            // had to check if we haven't already reached this state with a better cost
            if(cost[curr_node][fuel_left + 1] > cost[curr_node][fuel_left] + petrol[curr_node]){
                cost[curr_node][fuel_left + 1] = cost[curr_node][fuel_left] + petrol[curr_node];
                pq.push({-cost[curr_node][fuel_left + 1], {curr_node, fuel_left+1}});
            }
        }
    }

    // 0 petrol ke sath pahuchna jaruri hai? tabhi toh cost minimize hoga.
    cout << cost[en][0] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}