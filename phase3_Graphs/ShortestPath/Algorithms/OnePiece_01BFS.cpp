// https://maang.in/problems/One-Piece-902?resourceUrl=cs99-cp522-pl3553-rs902
// Q is about 0-1 bfs in a grid

/** 3 Implementation:
 * BFS using queue : TLE    (since a node gets added repeatedly to q here)
 * using priority_queue (more like Dijkstra) : works    , but could be improved since weights are just 0/1 and not anything random
 * use DEQUE : Best         push to front if wt is 0, back otherwise
 */
// So, the best way to implement a 0-1 bfs is using a deque

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

using state = pair<int, int>;
const int INF = 1e9;
vector<state> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
bool isValid(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grid(n+1, vector<int>(m+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    }

    // apply BFS with cost in wind dirn=0 and 1 otherwise.
    // sc=(0,0) goal=(n-1,m-1)
    // queue<state> q;
    // priority_queue<pair<int, state>> q;     // cost, node
    deque<state> dq;     // cost, node

    // Actual 0-1 BFS implementation is using a deque
    // push to front if cost 0, and back if 1.
    // does the work without explicity maintaining a heap (pq)

    vector<vector<int>> dist(n+1, vector<int>(m+1, INF));
    // q.push({0,0});
    // pq.push({0, {0,0}});
    dq.push_front({0,0});
    dist[0][0]=0;
    while(!dq.empty()){
        auto curr = dq.front();
        // state curr = temp.second;
        dq.pop_front();

        // for(auto it: moves){
        for(int i=0; i<4; i++){
            auto it = moves[i];
            int x = curr.first + it.first;
            int y = curr.second + it.second;

            // if windDir equal to moveDirn, wt=0
            int wt = (grid[curr.first][curr.second] != i+1);

            if(isValid(x, y, n, m) && (dist[x][y] > dist[curr.first][curr.second] + wt)){
                dist[x][y] = dist[curr.first][curr.second] + wt;
                // pq.push({-dist[x][y], {x, y}});
                if(wt==1) dq.push_back({x, y});
                else dq.push_front({x,y});
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}