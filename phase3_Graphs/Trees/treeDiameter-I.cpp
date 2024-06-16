// https://maang.in/problems/Tree-Diameter-I-427?resourceUrl=cs99-cp522-pl3600-rs427
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Trees are connected acyclic graph
// They have n-1 edges
// Diameter: Max distance b/w 2 nodes

/* Diameter Calculation:
 * The idea is to find the farthest node Y from any random node X
 * then call dfs again on Y to find farthest Z from Y
 * YZ dist will be the diameter!
*/

int n;
vector<vector<int>> adj;
vector<int> depth;

// vis array isn't req in trees, coz it consists of only simple paths
// a node will have max 2 connections only
// no need to clear depth arrays in multiple dfs calls, overwrite ho jati hai :)
void dfs(int node, int par){
    depth[node]= (par==0)?0: depth[par]+1;

    for(auto v: adj[node]){
        if(v != par){
            // depth[v] = depth[node]+1;
            dfs(v, node);
        }
    }
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    depth.resize(n+1, -1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // maxDist b/w 2 nodes ?
    // fix a source ?

    dfs(1, 0);
    int farthestNode=0;
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[farthestNode])
            farthestNode = i;
    }

    // call dfs again from farthest node
    dfs(farthestNode, 0);
    farthestNode=0;
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[farthestNode])
            farthestNode = i;
    }
    cout << depth[farthestNode] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}