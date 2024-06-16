// https://maang.in/problems/Area-and-Perimeter-of-Connected-Components-422?resourceUrl=cs99-cp522-pl3549-rs422
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Area: Size of component
// Perimeter: Cnt of border edges - either boundary or obstacle

// why '#' are treated not occupied here

int n;
vector<vector<int>> grid;

map<int, int> compSize;     // id, size
map<int, int> compPerimeter;     // id, perimeter
vector<vector<int>> moves = {{0,-1}, {0,1}, {-1,0}, {1,0}};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
void dfs(int sx, int sy, int id){
    // grid[sx][sy]= to_string(id);
    grid[sx][sy]= id;
    compSize[id]++;

    for(auto it: moves){
        int x = sx+it[0];
        int y= sy+it[1];
        if(isValid(x, y) && grid[x][y]==0){
            dfs(x, y, id);
        }
    }
}

void solve(){
    cin>>n;
    grid.resize(n, vector<int>(n));
    compSize.clear();

    // # - free in the q : mapped to 0
    // . - can't travel : mapped to -1
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin>>ch;
            if(ch=='.') grid[i][j]=-1;
            else grid[i][j]=0;
        }
    }

    int compID=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            // if(grid[i][j]=='#'){
            if(grid[i][j]==0){      // not visited
                compID++;
                compSize[compID]=0;
                dfs(i, j, compID);
            }
        }
    }

    // compSize is the area only

    // find perimeter - no. of edges
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==-1) continue;
            int comp = grid[i][j];
        
            // if(i==0) compPerimeter[comp]++;  
            // if(i==n-1) compPerimeter[comp]++;  
            // if(j==0) compPerimeter[comp]++;  
            // if(j==n-1) compPerimeter[comp]++;  

            for(auto it: moves){
                int x = i + it[0];
                int y = j + it[1];
                // if(grid[x][y]=='.')  {   // surrounded by occupied cell
                // if(isValid(x,y) && grid[x][y]==-1)  {  
                //     compPerimeter[comp]++;
                //     // grid[i][j]+=10;
                // }
                if(isValid(x, y)){
                    if(grid[x][y]==-1) compPerimeter[comp]++;
                }
                else {  // boundary
                    compPerimeter[comp]++;
                }

            }
        }
    }

    // print max area with least per
    int max_area=0, best_per=1e9;
    for(int comp=1; comp<=compID; comp++){
        if(compSize[comp] > max_area || (compSize[comp]==max_area && compPerimeter[comp] < best_per)){
            max_area = compSize[comp];
            best_per = compPerimeter[comp];
        }
    }

    cout << max_area << " " << best_per << "\n";

    // debug
    // cout << "compSize: " << compID << " : " << compSize[2]<< "\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++) {
    //         if(grid[i][j]==-1) cout << "_" << "\t";
    //         else cout << grid[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}