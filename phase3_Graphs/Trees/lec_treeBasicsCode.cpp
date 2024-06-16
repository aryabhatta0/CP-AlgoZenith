/* 
Given a tree with n nodes (1-indexed), determine for each node:
    1. isLeaf
    2. depth
    3. subTreeSize
    4. parent
    5. numChild
*/

// In a tree, there exists one simple path b/w any 2 nodes
// so ur bfs and dfs will give the same result i.e, shortest path
// dfs(u, 0, 0) will give u distance to all other nodes from u i.e, depth[v]

// use parent array to print the path

// Diameter of a tree: Longest Shortest Path
// i.e, max dist b/w any 2 nodes

#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int depth[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSize[100100];
int numChild[100100];

/* vis array isn't req in tree qs.
 * coz it consists of only simple paths and a node will have max 2 connections only

 * no need to clear any vector for another dfs calls, it just overwrites everything
*/
void dfs(int node, int parent, int dep){
    depth[node] = dep;
    par[node] = parent;

    subtreeSize[node]=1;
    numChild[node]=0;
    for(auto v: g[node]){
        if(v != parent){
            numChild[node]++;
            dfs(v, node, dep+1);
            subtreeSize[node] += subtreeSize[v];
        }
    }

    if(numChild[node]==0)
        isLeaf[node] = 1;
}

void solve(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){   // n-1 edges
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // rooted at 1
    dfs(1, 0, 0);

    // Diameter Calculation: 2 dfs calls
    dfs(1, 0, 0);
    int maxChild=1;
    for(int i=2; i<=n; i++){
        if(depth[i] > depth[maxChild])
            maxChild = depth[i];
    }
    dfs(maxChild, 0, 0);
    maxChild=1;
    for(int i=2; i<=n; i++){
        if(depth[i] > depth[maxChild])
            maxChild = depth[i];
    }

    int diameter = depth[maxChild];
    cout << diameter << "\n";
    //////////
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
}