#include <bits/stdc++.h>
using namespace std;

// The question is to find number of connected components after each edge removal query
// The idea is to approach edge removal as edge addition problem after reversing the queries. WOW.
// Thus we will be using DSU!

struct DSU {
    int n;
    vector<int> parent, rank1;
    int numComponents=0;

    DSU(int n) {
        this->n = n;
        parent.resize(n+1);
        rank1.resize(n+1);
        makeSet();

        numComponents = n;  // initially, there are n components
    }

    // initialize parent and rank1
    void makeSet() {
        for (int i = 1; i <=n; i++) {
            parent[i] = i;
            rank1[i] = 0;
        }
    }

    // returns the root of the tree
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);     // path compression
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        // rank compression
        if (rank1[x] < rank1[y]) parent[x] = y;
        else {
            parent[y] = x;
            if (rank1[x] == rank1[y]) rank1[x]++;
        }

        numComponents--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q; cin>>n>>m>>q;
    vector<pair<int, int>> edges(m+1);
    for(int i=1; i<=m; i++){
        int u, v; cin>>u>>v;
        edges[i] = {u, v};
    }

    vector<pair<int, int>> queries(q);
    vector<bool> toBeRemoved(m+1, false);

    for(int i=0; i<q; i++){
        int type; cin>>type;
        if(type==1){
            int x; cin>>x;
            queries[i] = {1, x};
            toBeRemoved[x] = true;
        }
        else queries[i] = {2, -1};
    }

    // making dsu - unite all the edges which are not to be removed
    DSU dsu(n);
    for(int i=1; i<=m; i++){
        if(!toBeRemoved[i]){
            dsu.unite(edges[i].first, edges[i].second);
        }
    }

    // now we have to answer the queries
    vector<int> ans;
    for(int i=q-1; i>=0; i--){
        if(queries[i].first == 1){
            int x = queries[i].second;
            dsu.unite(edges[x].first, edges[x].second);
        }
        else ans.push_back(dsu.numComponents);
    }

    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}