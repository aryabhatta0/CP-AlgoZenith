// https://maang.in/problems/Vertical-Grid-415?resourceUrl=cs117-cp540-pl3651-rs415&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: N*10 grid with values 0-9; 0 means empty, 1-9 denote colors of balls.
// Ball can fall downwards due to gravity, collapses if atleast K balls of same color gets accumulated together.
// The process continue repeating. Given intial state, return the final state of the game.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Hint: Try to figure out the different components of the solution. Follow brute force.
class DSU {
    int n;
    vector<int> par, rank;

    int find(int node){
        if(par[node]==node) return node;
        return par[node] = find(par[node]);
    }

public:
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(rank[x] >= rank[y]) {
            par[y] = x;
            rank[x] += rank[y];
        } else {
            par[x] = y;
            rank[y] += rank[x];
        }
    }

    // same as contructor
    void initialize(int n) {
        this->n=n;
        par.resize(n); rank.resize(n);
        reset();
    }

    void reset(){
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 1;
        }
    }

    // return CC size
    int getSize(int node) {
        node = find(node);
        return rank[node];
    }
};

class Game {
    int n, k;
    vector<vector<int>> grid;
    // Create a DSU to check CC sizes later
    DSU uf;

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
    
    vector<pair<int, int>> neigh {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool isValid(int x, int y){
        return x>=0 && x<n && y>=0 && y<10;
    }
    // merge CC to figure out their sizes later
    void merge() {
        // reinitialize DSU
        uf.reset();

        // merge all appropriate nodes
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if(grid[i][j]) {    // non-zero
                    for(auto it: neigh) {
                        int nx = i + it.first;
                        int ny = j + it.second;
                        if(isValid(nx, ny) && grid[nx][ny]==grid[i][j]) {
                            uf.merge(i*10+j, nx*10+ny);
                        }
                    }
                }
            }
        }
    }    

    // delete the CC with size>=K
    bool disappear() {
        bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                // cout << "size of (" << i << "," << j << ")" << uf.getSize(i*10+j) << "\n";
                if(uf.getSize(i*10+j) >= k) {
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

        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++) {
                char ch; cin>>ch;
                grid[i][j] = ch-'0';
            }
        }

        // Initialize DSU with 10n nodes
        uf.initialize(10*n);
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