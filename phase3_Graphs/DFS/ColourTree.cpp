// https://maang.in/problems/Colour-Tree-416?resourceUrl=cs99-cp522-pl3546-rs416
#include <bits/stdc++.h>
using namespace std;

// The question is to colour tree so that no two nodes with same colour are adjacent or separated by only two edges.
// Hint is to think about the node with maximum neighbours

int main(){
    int n; cin>>n;
    vector<int> Adj[n+1];
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int maxDeg = 0;
    for(int i=1; i<=n; i++){
        maxDeg = max(maxDeg, (int)Adj[i].size());
    }

    cout<<maxDeg+1<<"\n";
}