// TLE with BFS
// Check optimization using Dijkstra in onePiece2.cpp

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;
const ll INF = 1e18;

int n, m;
vector<vector<int>> grid;
vector<vector<ll>> dist;

vector<pair<state, int>> getNeighbours(state curr){
    vector<pair<state, int>> neighbours;    // {state, weight}
    int x = curr.first, y = curr.second;

    if(y+1<m) neighbours.push_back({{x, y+1}, grid[x][y]==1? 0 : 1});    // right
    if(y-1>=0) neighbours.push_back({{x, y-1}, grid[x][y]==2? 0 : 1});    // left
    if(x+1<n) neighbours.push_back({{x+1, y}, grid[x][y]==3? 0 : 1});    // down
    if(x-1>=0) neighbours.push_back({{x-1, y}, grid[x][y]==4? 0 : 1});    // up
    return neighbours;
}

void bfs(state sc){
    dist.resize(n, vector<ll>(m, INF));
    dist[sc.first][sc.second] = 0;

    queue<state> q;
    q.push(sc);
    while (!q.empty()) {
        state curr = q.front(); q.pop();

        for(auto it: getNeighbours(curr)){
            int x=it.first.first, y=it.first.second, w=it.second;
            if(dist[x][y] > dist[curr.first][curr.second]+w){
                dist[x][y] = dist[curr.first][curr.second]+w;
                q.push({x, y});
            }
        }
    }

    // cout << "dist:\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++)
    //         cout << dist[i][j] << " ";
    //     cout << "\n";
    // } cout << "\n";

    if(dist[n-1][m-1]==INF) cout << "-1\n";
    else cout << dist[n-1][m-1] << "\n";
    

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    }

    bfs({0, 0});
    return 0;
}