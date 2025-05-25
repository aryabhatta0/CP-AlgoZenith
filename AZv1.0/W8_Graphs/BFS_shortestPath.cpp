#include <bits/stdc++.h>
using namespace std;
#define ll long long

using state = pair<int, int>;
const int INF = 1e9;

int n, m; 
vector<vector<char>> grid;
vector<vector<int>> dist;
vector<vector<state>> par;     // to trace back the path
state sc, en;                // start and end coordinates

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

vector<state> getNeighbours(state curr){
    vector<state> neighbours;
    int x = curr.first, y = curr.second;
    if(isValid(x+1, y)) neighbours.push_back({x+1, y});
    if(isValid(x-1, y)) neighbours.push_back({x-1, y});
    if(isValid(x, y+1)) neighbours.push_back({x, y+1});
    if(isValid(x, y-1)) neighbours.push_back({x, y-1});
    return neighbours;
}

void bfs(state sc){
    queue<state> q;
    dist[sc.first][sc.second] = 0;
    q.push(sc);

    ll ans = -1;
    while(!q.empty()){
        state curr = q.front(); q.pop();

        for(auto x: getNeighbours(curr)){
            if(dist[x.first][x.second] > dist[curr.first][curr.second] + 1){
                dist[x.first][x.second] = dist[curr.first][curr.second] + 1;
                par[x.first][x.second] = curr;
                q.push(x);
            }
        }
    }
}

/** Input:
4 6
..#...
S.#.#.
....#.
..#..E
*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            if(grid[i][j] == 'S') {
                sc = {i, j};
            } else if(grid[i][j] == 'E') {
                en = {i, j};
            }
        }
    }
    
    dist.resize(n, vector<int>(m, INF));
    par.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    bfs(sc);
    cout << dist[en.first][en.second] << "\n";

    // print path
    vector<state> path;
    state curr = en;
    while(curr != sc){
        path.push_back(curr);
        curr = par[curr.first][curr.second];
    }
    path.push_back(sc);
    reverse(path.begin(), path.end());
    cout << "Path: \n";
    for(auto x: path) cout << x.first << " " << x.second << " -> ";
    cout << "\n";

    return 0;
}