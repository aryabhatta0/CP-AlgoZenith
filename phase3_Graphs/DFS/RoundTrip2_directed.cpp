#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Checking cycle on a DIRECTED graph
// the same logic doesn't apply to directed graph

// why another solve() gives TLE??

int n, m;
vector<vector<int>> adj;
vector<int> visited;
bool cycle_present = false;

void dfs(int sc){
    visited[sc] = 1;    // being visited

    for(auto v: adj[sc]){
        if(visited[v]==1) {
            cycle_present=1;
            return;
        }
        if(!visited[v]) dfs(v);
        if(cycle_present) return;
    }
    visited[sc]=2;  // already visited
}

void solve() {
	cin >> n >> m;
	adj.assign(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	visited.assign(n + 1, 0);
	cycle_present = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0)dfs(i);
	}
	if (!cycle_present)cout << "No" << endl;
	else cout << "Yes" << endl;
}

// void solve(){
//     cin>>n>>m;
//     adj.assign(n + 1, vector<int>());
//     int a, b;
//     while(m--){
//         cin>>a>>b;
//         adj[a].push_back(b);
//         // adj[b].push_back(a);
//     }

//     visited.assign(n+1, 0);
//     cycle_present=0;
//     for(int i=1; i<=n; i++){
//         if(!visited[i]){
//             dfs(i);
//         }
//         if(cycle_present) break;
//     }

//     if(cycle_present) cout << "Yes\n";
//     else cout << "No\n";
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}