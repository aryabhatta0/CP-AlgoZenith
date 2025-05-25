#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> par, rank;
    int cnt;
    
    DSU(int n){
        this->n=n;
        par.resize(n+1);
        rank.resize(n+1);
        cnt=0;
        init();
    }
    
    void init(){
        for(int i=1; i<=n; i++){
            par[i]=i;
            rank[i]=0;
        }
        cnt=n;	// n sets at the start
    }
    
    int findRoot(int x){
        if(par[x]==x) return x;
        // return findRoot(par[x]);
        return par[x] = findRoot(par[x]);
    }
    
    void unite(int x, int y){
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX==rootY) return;
        cnt--;
        
        if(rank[rootX] > rank[rootY]){
            par[rootY] = rootX;
        } else {
            par[rootX] = rootY;
            if(rank[rootX]==rank[rootY]) rank[rootY]++;
        }
    }
    // we are only adding, and not removing, right?
    
    bool same(int x, int y){
        return findRoot(x)==findRoot(y);
    }
    
    // not useful for this problem
    int getNumComp(){
        return cnt;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;

    DSU dsu(n);
    while(q--){
        int type, x, y; cin>>type>>x>>y;
        if(type==1) cout << dsu.same(x, y) << "\n";
        else dsu.unite(x, y);
    }
    
    return 0;
}