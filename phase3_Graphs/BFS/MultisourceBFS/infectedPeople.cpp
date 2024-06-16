// Multisource BFS
// https://maang.in/problems/Infected-People-589?resourceUrl=cs99-cp522-pl3549-rs589

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, m;
vector<vector<int>> city;

using state = pair<int, int>;
const int INF = 1e9;
vector<state> neighbours = {{1,0} ,{0,1} , {-1,0}, {0,-1}};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && city[x][y]!=0;
}

void solve(){
    cin>>n>>m;
    city.resize(n, vector<int>(m));
    vector<state> sc;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>city[i][j];
            if(city[i][j]==2) sc.push_back({i, j});
        }
    }

    // multisource BFS from cells with virus (val 2)
    queue<state> q;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    for(auto x: sc){
        q.push(x);
        dist[x.first][x.second]=0;
    }

    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto it: neighbours){
            int x = curr.first + it.first;
            int y = curr.second + it.second;

            if(isValid(x, y) && dist[x][y]==INF){
                dist[x][y] = dist[curr.first][curr.second] + 1;
                q.push({x, y});
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(city[i][j]!=0)
                ans = max(ans, dist[i][j]);
        }
    }

    if(ans==INF) cout << "-1\n";
    else cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}