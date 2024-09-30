// Tough but Imp Union Find Application
// https://maang.in/problems/Min-Edge-Weight-38?resourceUrl=cs99-cp522-pl3603-rs38
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


/* Intuition:
 * We need min edge sum for each pair of nodes path
  (we need sum of minimum edge in the path of each pair of nodes)

 * Edge Contribution:
  - edge ke dono end par tab tak ke nodes chahiye jab tak koi currEdge se bada naa aa jaye
  - sabhi edge hata do, and bade value se edge add karna start karo
 * Addition of Edge in a Tree => Union Find
 
 * No. of paths for a edge to be added will be given by rank of the two nodes of edge
 * Rank is nothing but the size of subtree containing the node
*/

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
    // rank of a node means the size of set/subtree containing node
    // and is stored in the rank of it's root
    int getRank(int x){
        return rank[find(x)];
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
    void print(){ for(int i=1; i<=n; i++) cout << i << " -> " << par[i] << "\n"; }
};

void solve(){
    int n; cin>>n;
    // we just need edges for union find
    set<pair<int, pair<int, int>>> edges;    // -cost, {nodes}
    for(int i=0; i<n-1; i++){
        int u, v, w; cin>>u>>v>>w;
        edges.insert({-w, {u, v}});      // -ve of cost to maintain a min heap
    }

    UnionFind uf(n);

    ll sum=0;
    for(auto it: edges){
        // DOUBT: What if the node will be already connected in UF, cycle?
        // Tree: Only simple unique paths exist
        
        int cost = -it.first;
        // cout << "adding sth: " << cost << "\n";
        auto edge = it.second;
        // edge contribution
        // all already added edge will be of higher cost
        // so rank can decide no. of paths, where this will be min edge
        sum += 1LL* cost * uf.getRank(edge.first) * uf.getRank(edge.second);    // cost * numPaths
        uf.merge(edge.first, edge.second);
    }

    cout << sum << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}