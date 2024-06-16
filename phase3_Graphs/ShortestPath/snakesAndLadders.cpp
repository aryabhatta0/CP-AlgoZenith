// https://maang.in/problems/Snakes-and-Ladders-927?resourceUrl=cs99-cp522-pl3598-rs927
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Soln:
 * Could be visualized just like bfs using go_immediately_to[101]
 * each node is connected to go_immediately_to[node + i]; i= 1,...,6
*/

const int INF=1e9;
void solve(){
    // vector<vector<int>> adj(101);   
    // must follow edges - end node of possible snake or ladder at i
    vector<int> adj(101, 0);
    int n; cin>>n;
    int u, v;
    while(n--){     // ladders
        cin>>u>>v;
        // adj[u].push_back(v);
        adj[u]=v;
    }
    int m; cin>>m;
    while(m--){     // snakes
        cin>>u>>v;
        // adj[u].push_back(v);
        adj[u]=v;
    }

    // bfs or dijkstra ?
    // (1-6)dice move costs 1 and must-follow edges cost 0
    // 0-1 BFS?
    deque<int> dq;
    vector<int> cost(101, INF);  // cost (num rolls) to reach nth node

    // 0wt is added at front, and 1wt at back
    dq.push_front(1);
    cost[1]=0;
    while(!dq.empty()){
        auto curr = dq.front();
        dq.pop_front();

        if(adj[curr]){  // must follow edge
            // can't do anything?
            // dq.push_front(adj[curr]);   // I suspect TLE
            if(cost[adj[curr]] > cost[curr]){
                cost[adj[curr]] = cost[curr];
                dq.push_front(adj[curr]); 
            }
        } else {
            for(int i=1; i<=6; i++){
                if(curr+i<101 && cost[curr+i] > cost[curr]+1 ){
                    cost[curr+i] = cost[curr]+1;
                    dq.push_back(curr+i);
                }
            }
        }
    }

    if(cost[100]==INF) cout << "-1\n";
    else cout << cost[100] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}