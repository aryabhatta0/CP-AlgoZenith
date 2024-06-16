// https://maang.in/problems/Android-Unlock-Pattern-486?resourceUrl=cs99-cp512-pl3524-rs486
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// connect n dots => 1 thing at a time => choices / levels => recursion!
int n;

// We are numbering the nodes as:
// 1 2 3
// 4 5 6
// 7 8 9

bool visited[10];
int skip[10][10];   // contains the node b/w (i,j)

// how many ways to fill remNode starting from start
int rec(int start, int remNode){
    if(remNode==0) return 1;    // just this 1 seq

    visited[start]=true;

    // choices
    int ans=0;
    for(int i=1; i<=9; i++){
        if(visited[i]==0 && visited[skip[start][i]]){
            ans += rec(i, remNode-1);
        }
    }

    // revert change
    visited[start]=false;
    return ans;
}

void solve(){
    cin>>n;    

    memset(visited, false, sizeof(visited));
    visited[0]=true;    // not a point. default.
    memset(skip, 0, sizeof(skip));

    // Brute-Force
    // These save the connection that skips a point.
    // to join 1 and 3, 2 needs to be pre-selected, or its invalid move.
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;

    int ans=0;
    // Using symmetry:
    // Starting from 1 3 7 9 all will be similar
    ans += rec(1, n - 1) * 4;   
    // Starting from 2 4 6 8 all will be similar
    ans += rec(2, n - 1) * 4;   
    ans += rec(5, n - 1);

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}