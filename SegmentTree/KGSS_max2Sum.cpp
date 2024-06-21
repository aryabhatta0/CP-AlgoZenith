// https://www.spoj.com/problems/KGSS/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// NOTE: A default constructor will be needed when resizing tree vector of nodes
struct node {
    int max1, max2;
    node(int m1=-1, int m2=-1){
        max1=m1; max2=m2;
    }
};

node merge(node a, node b){
    vector<int> values = {a.max1, a.max2, b.max1, b.max2};
    sort(values.rbegin(), values.rend());       // descending

    return node(values[0], values[1]);
}

class segmentTree {
private:
    int n;
    vector<node> tree;

    void build(vector<int>& arr, int nodeInd, int st, int en){
        if(st==en){
            // leaf node
            tree[nodeInd] = node(arr[st]);
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*nodeInd, st, mid);
        build(arr, 2*nodeInd+1, mid+1, en);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    void update(int nodeInd, int st, int en, int pos, int x){
        if(pos<st || pos>en) return;
        if(st==en){
            // leaf node
            tree[nodeInd] = node(x);
            return;
        }

        int mid = (st+en)/2;
        update(2*nodeInd, st, mid, pos, x);
        update(2*nodeInd+1, mid+1, en, pos, x);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    node query(int node, int st, int en, int l, int r){
        // bahar
        if(en<l || r<st) return 0;
        // andar
        if(l<=st && en<=r) return tree[node];

        int mid = (st+en)/2;
        return merge(query(2*node, st, mid, l, r), query(2*node+1, mid+1, en, l, r));
    }

public:
    segmentTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void update(int i, int x){
        update(1, 0, n-1, i, x);
    }

    ll query(int x, int y){
        node res = query(1, 0, n-1, x, y);
        return res.max1 + res.max2;
    }
};

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    segmentTree segTree(arr);

    int q; cin>>q;
    while(q--){
        char ch; int x, y; 
        cin>>ch>>x>>y;
        if(ch=='U') segTree.update(x-1, y);
        else cout << segTree.query(x-1, y-1) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}