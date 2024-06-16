// new attempt
// https://maang.in/problems/Save-Yourself-195?resourceUrl=cs99-cp522-pl3549-rs195

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, m;
vector<vector<char>> grid;

using state = pair<int, int>;
const int INF = 1e9;
vector<state> neigbours = {{1,0} ,{0,1} , {-1,0}, {0,-1}};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

void solve(){
    cin>>n>>m;
    grid.resize(n, vector<char>(m));
    vector<state> monsters;
    state p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='M') monsters.push_back({i, j});
            else if(grid[i][j]=='A') p = {i, j};
        }
    }

    // we've to find dist of each boundary end point to person and nearest monsters
    // if there exists one so that person is near than all monsters, PERSON CAN ESCAPE

    queue<state> q;
    // monsters
    vector<vector<int>> distMonsters(n, vector<int>(m, INF));

    // add all the monsters to queue - multisource BFS from M_super
    for(auto m: monsters){
        q.push(m);
        distMonsters[m.first][m.second] = 0;
    }
    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto it: neigbours){
            int x = curr.first + it.first;
            int y = curr.second + it.second;

            if(isValid(x, y) && distMonsters[x][y]==INF){
                distMonsters[x][y] = distMonsters[curr.first][curr.second] + 1;
                q.push({x, y});
            }
        }
    }

    // person
    vector<vector<int>> distPerson(n, vector<int>(m, INF));
    q.push(p);
    distPerson[p.first][p.second] = 0;
    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto it: neigbours){
            int x = curr.first + it.first;
            int y = curr.second + it.second;

            if(isValid(x, y) && grid[x][y]!='M' && distPerson[x][y]==INF){
                distPerson[x][y] = distPerson[curr.first][curr.second] + 1;
                q.push({x, y});
            }
        }
    }

    // if there exists a boundary point whose dist to p is less than dist to any monsters
    int ans = INF;
    for(int i=0; i<n; i++){
        if(distPerson[i][0] < distMonsters[i][0]) ans = min(ans, distPerson[i][0]);
        if(distPerson[i][m-1] < distMonsters[i][m-1]) ans = min(ans, distPerson[i][m-1]);
    }
    for(int j=0; j<m; j++){
        if(distPerson[0][j] < distMonsters[0][j]) ans = min(ans, distPerson[0][j]);
        if(distPerson[n-1][j] < distMonsters[n-1][j]) ans = min(ans, distPerson[n-1][j]);
    }

    if(ans!=INF){
        cout << "YES\n" << ans << "\n";
    } else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}