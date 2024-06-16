#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 * CONCEPT: We can always think of removal as addition in reverse order!

 * We've to find #CC after each removal.
  - Removal ke baad wohi edge bache honge, jinhe hum aage remove karne wale hai
  - toh kyu naa unn sab ko add kar ke, #CC bata de 
  - since we know how to add edges :)
*/

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
            rank[i]=1;      // by size
        }
        numComponents=n;
    }

    int find(int x){
        if(x==par[x]) return x;
        return par[x] = find(par[x]);   // path compression
    }

    void merge(int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        if(xroot==yroot) return;

        if(rank[xroot]>=rank[yroot]){
            par[yroot] = xroot;
            rank[xroot] += rank[yroot];
        } else {
            par[xroot] = yroot;
            rank[yroot] += rank[xroot];
        }
        numComponents--;
    }

    int getNumComponents(){
        return numComponents;
    }
    // for debug
    void print(){ for(int i=1; i<=n; i++) cout << i << " -> " << par[i] << "\n"; } 
};

void solve(){
    int n, m, q; cin>>n>>m>>q;
    vector<pair<int, int>> edges(m+1);
    for(int i=1; i<=m; i++){
        int u, v; cin>>u>>v;
        // edges.push_back({u, v});
        edges[i] = {u, v};
    }

    vector<pair<int, int>> queries;
    vector<bool> toBeRemoved(m+1, false);   // not every edge will be removed
    
    for(int i=0; i<q; i++){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x;
            queries.push_back({1, x});
            toBeRemoved[x]=true;
        }
        else queries.push_back({2,0});
    }

    unionFind uf(n);    // maintaining dsu
    // unite all the edges which are not to be removed
    for(int i=1; i<=m; i++){
        if(toBeRemoved[i]==false){
            uf.merge(edges[i].first, edges[i].second);
        }
    }

    // cout << "uf: "; uf.print();

    // process queries in rev order
    vector<int> ans;
    for(int i=q-1; i>=0; i--){
        if(queries[i].first==2){
            ans.push_back(uf.getNumComponents());
        }
        else {
            int x = queries[i].second;
            uf.merge(edges[x].first, edges[x].second);
        }
    }

    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}