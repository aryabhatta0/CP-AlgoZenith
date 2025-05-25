#include <bits/stdc++.h>
using namespace std;

/*

6
##....
....#.
.#..#.
.#####
...###
....##

no. of # = 15
no. of . = 21

Output the area and perimeter of the largest connected component
ans (13, 22) how??


*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    }
}