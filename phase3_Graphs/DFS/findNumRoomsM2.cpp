// https://maang.in/problems/Find-the-Number-of-Rooms-191?resourceUrl=cs99-cp522-pl3546-rs191
// M2: Another way of implementing same thing
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Exploring Graph-like structures : DFS
// Choices to move?! : Neighbours

int n, m;
vector<vector<char>> grid;

vector<vector<int>> moves = {{0,-1}, {0,1}, {-1,0}, {1,0}};

bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void dfs(int sx, int sy){
    grid[sx][sy]='#';

    for(auto it: moves){
        int x = sx+it[0];
        int y= sy+it[1];
        if(isValid(x, y) && grid[x][y]!='#'){
            dfs(x, y);
        }
    }
}

void solve(){
    // connected components ?!
    cin>>n>>m;
    grid.resize(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }

    int rooms=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(grid[i][j]!='#'){
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}