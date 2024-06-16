// https://maang.in/problems/Connected-Component-Size-684?resourceUrl=cs99-cp522-pl3547-rs684
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// using map for compSize is more feasible
// why vector was giving RuntimeError ?
// also why'd one solve this using bfs?

int n, m;
vector<vector<int>> matrix;
// vector<vector<int>> comp;   // stores compID
// do it in matrix only compID starts from 2
// vector<int> compSize;
map<int, int> compSize;     // id, size


vector<vector<int>> moves = {{0,-1}, {0,1}, {-1,0}, {1,0}};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void dfs(int sx, int sy, int id){
    matrix[sx][sy]=id;
    // compSize.back()++;
    compSize[id]++;

    for(auto it: moves){
        int x = sx+it[0];
        int y= sy+it[1];
        if(isValid(x, y) && matrix[x][y]==0){
            dfs(x, y, id);
        }
    }
}

void solve(){
    cin>>n>>m;
    // matrix.resize(n, vector<int>(m));
    matrix.assign(n, vector<int>(m, 0)); // Resizing and initializing the matrix
    compSize.clear();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>matrix[i][j];
    }

    int compID=1;   // compID starts with 2
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(matrix[i][j]==0){
                compID++;
                // compSize.push_back(0);  // new elem to track size of new id
                compSize[compID]=0;
                dfs(i, j, compID);
            }
        }
    }

    // Debug
    // cout << "Matrix with ID: \n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++) cout << matrix[i][j] << " "; 
    //     cout << "\n";
    // }
    // cout << "CompSizes: ";
    // for(auto it: compSize) cout << it << " ";
    // cout << "\n";
    // cout << "\n";

    // update matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(matrix[i][j]!=1){
                int id = matrix[i][j];
                // if(compSize[id-2]==1) matrix[i][j]=0;
                // else matrix[i][j] = compSize[id-2];
                if(compSize[id]==1) matrix[i][j]=0;
                else matrix[i][j] = compSize[id];
            }

            // print it here only
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}