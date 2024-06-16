// Std MST problem
// https://maang.in/problems/Road-Reparation-206?resourceUrl=cs99-cp522-pl3602-rs206
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct unionFind {
    int n;
    vector<int> par, rank;
    int numComponents;
    unionFind(int n){
        this->n=n;
        par.resize(n+1); 
        rank.resize(n+1);
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
    bool same(int x,int y){
        return (find(x)==find(y));
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
    int getComponent() {return numComponents; }
};

void solve(){
    int n, m; cin>>n>>m;
    // vector<vector<pair<int, int>> adj(n+1);     // stores all {b,c} for each a
    // we won't need the adj list, we just have to find min egge route to connect all nodes - MST

    set<pair<int, pair<int, int>>> edges;    // c, {a, b}
    while(m--){
        int a, b, c; cin>>a>>b>>c;
        edges.insert({c, {a, b}});
    }

    // create a union fine tree
    unionFind uf(n);
    // initially all the nodes will be disconnected

    ll cost=0;
    for(auto it: edges){
        auto road = it.second;
        if(uf.merge(road.first, road.second)){
            cost += it.first;   // if succesfully merged i.e, not already connected
        }
    }

    if(uf.getComponent()==1) cout << cost << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}