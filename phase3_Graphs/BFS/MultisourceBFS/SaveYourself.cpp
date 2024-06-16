// multisource BFS
// Monsters on a grid

#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;
const int INF = 1e9;

int n, m;
vector<vector<char>> grid;
vector<state> monsters;
state sc;
vector<vector<int>> distOfMonsters, distOfPerson;

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

// for each end point, we will find dist to closest monster and person
void bfs(){

    // dist to closest monster
    queue<state> q;
    for(auto x: monsters) {
        q.push(x);
        distOfMonsters[x.first][x.second] = 0;
    }

    while(!q.empty()){
        state curr = q.front(); q.pop();

        for(auto it: getNeighbours(curr)){
            if(distOfMonsters[it.first][it.second] > distOfMonsters[curr.first][curr.second] + 1){
                distOfMonsters[it.first][it.second] = distOfMonsters[curr.first][curr.second] + 1;
                q.push(it);
            }
        }
    }

    // dist to person
    q.push(sc);
    distOfPerson[sc.first][sc.second] = 0;

    while(!q.empty()){
        state curr = q.front(); q.pop();

        for(auto it: getNeighbours(curr)){
            if(distOfPerson[it.first][it.second] > distOfPerson[curr.first][curr.second] + 1){
                distOfPerson[it.first][it.second] = distOfPerson[curr.first][curr.second] + 1;
                q.push(it);
            }
        }
    }

    int ans = INF;

    // check if person can escape from any of the 4 edges
     // right or left edge
    for(int i=0; i<n; i++){
        if(distOfPerson[i][0] < distOfMonsters[i][0]) ans = min(ans, distOfPerson[i][0]);
        if(distOfPerson[i][m-1] < distOfMonsters[i][m-1]) ans = min(ans, distOfPerson[i][m-1]);
    }
     // top or bottom edge
    for(int j=0; j<m; j++){
        if(distOfPerson[0][j] < distOfMonsters[0][j]) ans = min(ans, distOfPerson[0][j]);
        if(distOfPerson[n-1][j] < distOfMonsters[n-1][j]) ans = min(ans, distOfPerson[n-1][j]);
    }

    if(ans==INF) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<ans<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='M') monsters.push_back({i, j});
            else if(grid[i][j]=='A') sc = {i, j};
        }
    }

    distOfMonsters.resize(n, vector<int>(m, INF));
    distOfPerson.resize(n, vector<int>(m, INF));

    bfs();
    return 0;
}