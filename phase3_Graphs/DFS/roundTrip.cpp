// https://maang.in/problems/Round-Trip-194?resourceUrl=cs99-cp522-pl3548-rs194
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// This prb is about finding a cycle in a graph
// if we reach a visited node other than par again, a cycle exits
// A vis array, and par needs to be maintained

int n, m;
vector<vector<int>> adj;
vector<int> visited;
bool cycle_present = false;

void dfs(int sc, int par){
    visited[sc] = 1;

    for(auto v: adj[sc]){
        if(visited[v] && v!=par) {
            cycle_present=1;
            return;
        }
        if(!visited[v]) dfs(v, sc);
        if(cycle_present) return;
    }
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1, 0);
    int a, b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cycle_present=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, 0);
        }
        if(cycle_present) break;
    }

    if(cycle_present) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}