// https://maang.in/problems/Center-of-Tree-429?resourceUrl=cs99-cp522-pl3600-rs429
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;

/*
 * Centre of tree is the midpoint of any diameter.
 * It's unique and a property of tree.
 * There are at max 2 centres, and every dia pass through them.
 * 
 * For the implementation, centre isn't any node at dia/2 depth.
 * Need to track the path of dia!
*/

void dfs(int node, int par){
    depth[node] = (par==0)?0:depth[par]+1;
    parent[node] = par;

    for(int v: adj[node]){
        if(v != par){
            dfs(v, node);
        }
    }
}

void solve(){
    cin>>n;
    // if(n == 1) {         // this test case is imp
    //     cout<<1<<endl;
    //     return;
    // }

    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth.resize(n+1, -1);
    parent.resize(n+1, -1);

    dfs(1,0);
    int start=0;     // farthest from 1
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[start]){
            start = i;
        }
    }

    dfs(start, 0);
    int end=0;  // other end of dia
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[end]){
            end = i;
        }
    }

    // cout << start << " " << end << "\n";

    // diameter
    int dia = depth[end];

    // finding centre
    if(dia%2 != 0){         // multiple centre
        cout << "-1\n";
        return;
    } 

    // centre isn't just any node at depth D/2 !

    // traverse path from end
    auto it = end;
    while(it != start){
        if(depth[it]==dia/2){
            // cout << it << "\n";
            break;
        }
        it = parent[it];
    }
    cout << it << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}