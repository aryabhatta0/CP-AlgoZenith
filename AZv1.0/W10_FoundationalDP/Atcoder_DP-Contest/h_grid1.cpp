#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

// dp[i][j]: no. of ways to reach (h-1,w-1) from (i,j)
// ans = dp[0][0]

int h, w; 
vector<vector<char>> grid;
vector<vector<ll>> dp;

ll rec(int i, int j){
    if(i>=h || j>=w || grid[i][j]=='#') return 0;
    if(i==h-1 && j==w-1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    // choices
    return dp[i][j] = (rec(i+1, j) + rec(i, j+1)) % mod;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>h>>w;
    grid.resize(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>grid[i][j];
    }

    dp.resize(h, vector<ll>(w, -1));
    cout << rec(0, 0) << "\n";
}