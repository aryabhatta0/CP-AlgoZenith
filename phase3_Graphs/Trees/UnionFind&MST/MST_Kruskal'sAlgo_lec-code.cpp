#include <bits/stdc++.h>
using namespace std;
#define ll long long


/* Minimum Spanning Tree (of a graph):
 * Spanning trees are the ones that connects all the nodes in a graph
 * MST is the one with the minimum cost of spanning tree, given edge-weights.
 * 
 * Implementation: Kruskal's Algo
 * Store edges in sorted order of their weights.
 * Maintain a Union Find to connect edges one-by-one.
 * Start connecting nodes with lower edge weight, if not already connected.
*/


/** Union Find Template */
struct UnionFind {
    int n;
    vector<int> par, rank;
    int numComponents;

    UnionFind(int n){
        this->n=n;
        par.resize(n+1); rank.resize(n+1);
        for(int i=1; i<=n; i++){
            par[i]=i;
            rank[i]=1;
        }
        numComponents=n;
    }

    int find(int x){
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return 0;

        if(rank[x] >= rank[y]){
            par[y] = x;
            rank[x] += rank[y];
        } else {
            par[x] = y;
            rank[y] += rank[x];
        }
        numComponents--;
        return 1;
    }

    int getRank(int x){
        return rank[find(x)];
    }
    int getNumComponent() {return numComponents; }
    void print(){ for(int i=1; i<=n; i++) cout << i << " -> " << par[i] << "\n"; }
};

void solve(){
    int n, m; cin>>n>>m;
    UnionFind uf(n);

    set<pair<int, pair<int, int>>> edges;    // c, {a, b}
    while(m--){
        int a, b, c; cin>>a>>b>>c;
        edges.insert({c, {a, b}});
    }

    ll mst_cost=0;
    int cnt=0;
    for(auto it: edges){
        int x = it.second.first;
        int y = it.second.second;
        if(uf.merge(x, y)){
            cnt++;
            mst_cost += it.first;   // if succesfully merged i.e, not already connected
        }

        // we've updated merge to return a bool to check if x&y is to be merged or they're already connected
        // if(uf.find(x)!=uf.find(y)){
        //     mst_cost += it.first;
        //     uf.merge(x,y);
        // }
    }

    // if(cnt!=n-1) cout << "No Solution\n";

    if(uf.getNumComponent()==1) cout << mst_cost << "\n";
    else cout << "No Solution\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}