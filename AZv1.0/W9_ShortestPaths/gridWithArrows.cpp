#include <bits/stdc++.h>
using namespace std;

/** Syntax=>  (Exp) ? Val1 : Val2  */

using state = pair<int, int>;
const int INF = 1e9;

int n, m;
vector<vector<char>> grid;
state sc, en;
vector<vector<int>> dist;
vector<vector<state>> par;

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

vector<pair<state, int>> getNeighbours(state curr){
    vector<pair<state, int>> neighbours;
    int x = curr.first, y = curr.second;
    char ch = grid[x][y];
    // cout << "curr: " << x << " " << y << " ch=" << ch << endl;
    if(isValid(x+1, y)) neighbours.push_back({{x+1, y}, ch=='D'?0:1});
    if(isValid(x-1, y)) neighbours.push_back({{x-1, y}, ch=='U'?0:1});
    if(isValid(x, y+1)) neighbours.push_back({{x, y+1}, ch=='R'?0:1});
    if(isValid(x, y-1)) neighbours.push_back({{x, y-1}, ch=='L'?0:1});

    // cout << "neighbours: " << endl;
    // for(auto x: neighbours) cout << x.first.first << " " << x.first.second << " path=" << x.second << endl;
    return neighbours;
}

void bfs(state sc){
    queue<state> q;
    q.push(sc);
    dist[sc.first][sc.second] = 0;

    while(!q.empty()){
        state curr = q.front(); q.pop();
        
        for(auto x: getNeighbours(curr)){       // (neighbour, weight)
            if(dist[x.first.first][x.first.second] > dist[curr.first][curr.second] + x.second){
                dist[x.first.first][x.first.second] = dist[curr.first][curr.second] + x.second;
                par[x.first.first][x.first.second] = curr;
                // cout << "pushing: " << x.first.first << " " << x.first.second << " path=" << x.second << endl;
                q.push(x.first);
            }
        }
    }
}

/**

3 3
RDR
RRU
LLL
0 0 2 0

*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            // if(grid[i][j]=='S') sc = {i, j};
            // else if(grid[i][j]=='E') en = {i, j};
        }
    }

    // cout << "\nEnter start and end state: ";
    cin>>sc.first>>sc.second>>en.first>>en.second;


    dist.resize(n, vector<int>(m, INF));
    par.resize(n, vector<state>(m, {-1, -1}));

    bfs(sc);
    cout << "Ans= " << dist[en.first][en.second] << endl;

    // print dist
    cout << "Dist: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << dist[i][j] << " ";
        cout << endl;
    }

    // path reconstruction
    vector<state> path;
    state curr = en;
    while(curr != sc){
        path.push_back(curr);
        curr = par[curr.first][curr.second];
    }
    path.push_back(sc);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for(auto x: path) cout << x.first << "," << x.second << " -> ";
    cout << endl;

    return 0;
}