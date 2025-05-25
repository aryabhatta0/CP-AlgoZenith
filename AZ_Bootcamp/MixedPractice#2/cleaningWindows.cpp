#include <bits/stdc++.h>
using namespace std;

/** Intuition:
 * For each (i,j) , see isko kab saaf kar rahe hai
 * Agar iske upar ka triangle region mein kisiko iske baad saaf karenge, toh yeh ganda rahega
 */

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> pre(n, vector<int>(m));     // max of upward tria at (i,j)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];

            pre[i][j] = 0;
            if(i-1>=0) {
                pre[i][j] = max(arr[i-1][j], pre[i-1][j]);
                if(j-1>=0) pre[i][j] = max({pre[i][j], arr[i-1][j-1], pre[i-1][j-1]});
                if(j+1<m) pre[i][j] = max({pre[i][j], arr[i-1][j+1], pre[i-1][j+1]});
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(pre[i][j] > arr[i][j]) arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout << arr[i][j];
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}