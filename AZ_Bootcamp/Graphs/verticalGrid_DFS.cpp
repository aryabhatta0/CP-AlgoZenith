// https://maang.in/problems/Vertical-Grid-415?resourceUrl=cs117-cp540-pl3651-rs415&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: N*10 grid with values 0-9; 0 means empty, 1-9 denote colors of balls.
// Ball can fall downwards due to gravity, collapses if atleast K balls of same color gets accumulated together.
// The process continue repeating. Given intial state, return the final state of the game.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using state = pair<int, int>;

// Another prb for reference: https://leetcode.com/problems/flood-fill/
/** Better way to code gravity():
 * To apply gravity, we can simply count the number of '0' squares in each column (from the bottom going up) until we reach an occupied square. Then, we shift that column down by that number of squares.
 */
class Game {
    int n, k;
    vector<vector<int>> grid;
    vector<vector<int>> region;     // to name each CC
    vector<int> regsize;   // to store sizes of each CC named

    // make things fall
    void gravity( ){
        // make each col fall
        for(int i=0; i<10; i++){
            vector<int> col;    // store non-zero values from bottom
            for(int row=n-1; row>=0; row--){
                if(grid[row][i]!=0) col.push_back(grid[row][i]);
            }

            // put col from bottom
            int it=0;
            for(int row=n-1; row>=0; row--) {
                if(it<col.size()) grid[row][i] = col[it++];
                else grid[row][i] = 0;
            }
        }
    }
    
    vector<state> neigh {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool isValid(int x, int y){
        return x>=0 && x<n && y>=0 && y<10;
    }

    // {x, y} is the source
    // flood is the val you'd look for in neighbot (flood fill)
    // id is the unique id being assigned to each CC
    void dfs(int x, int y, int flood, int id) {
        region[x][y] = id;
        regsize[id]++;

        for(auto it: neigh){
            int nx = x + it.first;
            int ny = y + it.second;

            if(isValid(nx, ny) && region[nx][ny]==0 && grid[nx][ny]==flood) {
                dfs(nx, ny, flood, id);
            }
        }
    }

    // merge CC to figure out their sizes later
    void merge() {
        // reset
        region.assign(n, vector<int>(10, 0));
        regsize.assign(10*n, 0);

        int id=1;
        // call dfs on all unvisited (id=0) node with new id
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if(grid[i][j]!=0 && region[i][j]==0) {
                    dfs(i, j, grid[i][j], id++);
                }
            }
        }
    }    

    // delete the CC with size>=K
    bool disappear() {
        bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                // cout << "size of (" << i << "," << j << ")" << regsize[region[i][j]] << "\n";
                if(grid[i][j]!=0 && regsize[region[i][j]] >= k) {
                    flag = true;
                    grid[i][j] = 0;     // disappear
                }
            }
        }

        return flag;    // if you've deleted something
    }

public:
    Game(int n, int k){
        this->n=n; this->k=k;
        grid.resize(n, vector<int>(10, 0));
        region.resize(n, vector<int>(10, 0));
        regsize.resize(10*n, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++) {
                char ch; cin>>ch;
                grid[i][j] = ch-'0';
            }
        }
    }

    void play(){
        while(1) {
            gravity();
            merge();
            bool flag = disappear();

            // when you've delted something
            if(!flag) break;  
        }

        view();
    }

    void view() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<10; j++) cout<<grid[i][j];
            cout << "\n";
        }
    }
};

void solve(){
    int n, k; cin>>n>>k;
    Game game(n, k);
    game.play();
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}