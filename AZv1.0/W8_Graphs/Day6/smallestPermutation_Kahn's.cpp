#include <bits/stdc++.h>
using namespace std;

// The problem is about finding lexico smallest topological ordering of a DAG
// using Kahn's algorithm

int n, m;
vector<vector<int>> Adj;
vector<int> indeg;
vector<int> topo;

void kahn(){
    priority_queue<int> pq;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) pq.push(-i);
    }

    while(!pq.empty()){
        int curr = -pq.top(); pq.pop();
        topo.push_back(curr);
        // del curr - update indeg of its neighbours
        for(auto v: Adj[curr]){
            indeg[v]--;
            if(indeg[v]==0) pq.push(-v);
        }
    }
}

int main(){
    cin>>n>>m;
    Adj.resize(n+1);
    indeg.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        Adj[u].push_back(v);
        indeg[v]++;
    }

    kahn();

    if(topo.size()!=n) cout << "-1\n";
    else {
        for(auto it: topo) cout << it << " ";
        cout << "\n";
    }
    return 0;
}