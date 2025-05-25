#include<bits/stdc++.h>
using namespace std;
#define ll long long

// The prb is like finding the number of connected components in a graph
// Idea is to iterate over the grid and whenever we find a floor (unvis), inc the room count and make all connected floors (neighbours) as wall (visited)

int n, m; 
vector<vector<char>> grid;

/** 
 * In std dfs, we have a visited array
 * And we iterate over neigbours and recurse (dfs) on them if unvisited
*/

// dfs to make all connected floors as wall (visited)
void dfs(int i, int j){
    // return if out of bounds or if wall (visited)
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#') return;
    grid[i][j] = '#';

    // recurse on neighbours
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    grid.resize(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }


    int roomCount = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.'){      // if unvisited (floor)
                roomCount++;
                dfs(i, j);
            }
        }
    }

    cout<<roomCount<<"\n";
}