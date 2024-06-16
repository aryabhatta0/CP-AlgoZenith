#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct unionFind {
    int n;
    vector<int> root;   // path compression
    vector<int> rank;   // rank compression by size
    unionFind(int n){
        this->n=n;
        root.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            root[i]=i;
            rank[i]=1;
        }
    }

    // int find(int x){
    //     if(root[x]==x) return x;
    //     return root[x] = root[root[x]];
    // }
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]); // path compression
    }

    bool same(int x, int y){
        return find(x)==find(y);
    }

    void unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx==rooty) return;

        if(rank[rootx] >= rank[rooty]){
            // smaller-to-larger-trick
            root[rooty] = rootx;
            rank[rootx] += rank[rooty];
        } else {
            root[rootx] = rooty;
            rank[rooty] += rank[rootx];
        }
    }
};

void solve(){
    int n, q; cin>>n>>q;

    unionFind uF(n);
    while(q--){
        int com, x, y;
        cin>>com>>x>>y;
        if(com==1){
            if(uF.same(x, y)){
                cout << "1\n";
            } else
                cout << "0\n";
        }
        else 
            uF.unite(x, y);
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}