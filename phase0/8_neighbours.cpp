#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isValid(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}

int solve(){
    int n, m; cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>arr[i][j];
    }
    int x, y; cin>>x>>y;

    if(isValid(x-1, y-1, n, m) && arr[x-1][y-1]=='.') return 0;
    if(isValid(x-1, y, n, m) && arr[x-1][y]=='.') return 0;
    if(isValid(x-1, y+1, n, m) && arr[x-1][y+1]=='.') return 0;

    if(isValid(x, y-1, n, m) && arr[x][y-1]=='.') return 0;
    if(isValid(x, y+1, n, m) && arr[x][y+1]=='.') return 0;

    if(isValid(x+1, y-1, n, m) && arr[x+1][y-1]=='.') return 0;
    if(isValid(x+1, y, n, m) && arr[x+1][y]=='.') return 0;
    if(isValid(x+1, y+1, n, m) && arr[x+1][y+1]=='.') return 0;

    // int res=1;
    // if(x-1 >= 0){
    //     if(y-1>=0 && arr[x-1][y-1]=='.') return 0;
    //     if(arr[x-1][y]=='.') return 0;
    //     if(y+1<m && arr[x-1][y+1]=='.') return 0;
    // }

    // if(y-1>=0 && arr[x][y-1]=='.') return 0;
    // if(y+1<m && arr[x][y+1]=='.') return 0;

    // if(x+1 < n){
    //     if(y-1>=0 && arr[x+1][y-1]=='.') return 0;
    //     if(arr[x+1][y]=='.') return 0;
    //     if(y+1<m && arr[x+1][y+1]=='.') return 0;
    // }

    return 1;
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int res = solve();
        if(res==1) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}