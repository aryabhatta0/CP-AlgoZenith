#include <bits/stdc++.h>
using namespace std;

// Standard DSU implementation
// What is DSU? Implementing disjoint sets DS with operations such as unite, find, same, count etc.
// Implementation: Parent trees with rank/size and path compression ideas for optimization

struct DSU{
    int n;
    vector<int> parent, rank1;

    DSU(int n){
        this->n = n;
        parent.resize(n);
        rank1.resize(n);
        makeSet();
    }

    // initialize
    void makeSet(){
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank1[i] = 0;
        }
    }

    // returns the root of the tree
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);     // path compression
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;

        // rank compression
        if(rank1[x] < rank1[y]) parent[x] = y;
        else{
            parent[y] = x;
            if(rank1[x] == rank1[y]) rank1[x]++;
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
    DSU dsu(n);
    int type, x, y;

    while(q--){
        cin>>type>>x>>y;
        if(type==0) dsu.unite(x, y);
        else cout << dsu.same(x, y) << "\n";
    }
    return 0;
}