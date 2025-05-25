#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m; 
vector<vector<int>> Adj;
vector<bool> vis;
vector<int> par;
bool cycle_present = false;
vector<int> cycle;

// This prb is about finding a cycle in a graph
// We have printed the cycle as well, have to check or debug

void dfs(int u){
    if(cycle_present) return;   

    vis[u] = true;
    for(int v : Adj[u]){
        if(!vis[v]){
            par[v] = u;     // calling dfs on v from u
            dfs(v);
        } else if(v != par[u]){
            cycle_present = true;
            int cur = u;
            // cout << "u is: " << u << "\n";
            // cout << "Cycle present at: " << v << "\n";
            while(cur != v && cur != 0){
                // cout << "pushing " << cur << "\n";
                cycle.push_back(cur);
                cur = par[cur];
            }
            // cycle.push_back(v);  // 2 baar call yaha aata, and yeh ho jayega push
        }
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        if(cycle_present) return;
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    Adj.resize(n+1);
    vis.resize(n+1, false);
    par.resize(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    solve();

    if(cycle_present) cout<<"YES\n";
    else cout<<"NO\n";

    if(cycle_present){
        cout << "Cycle: ";
        for(int i=0; i<cycle.size(); i++) cout<<cycle[i]<<" ";
        cout<<"\n";
    }

    return 0;
}