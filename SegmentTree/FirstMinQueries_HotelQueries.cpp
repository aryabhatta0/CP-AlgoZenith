// https://maang.in/problems/First-Min-Queries-403?resourceUrl=cs78-cp492-pl3320-rs403
// https://cses.fi/problemset/task/1143/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int maxi;
    node(int m=-1){
        maxi=m;
    }
};

node merge(node a, node b){
    return node(max(a.maxi, b.maxi));
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
            tree[nodeInd].maxi -=x;
            return;
        }

        int mid = (st+en)/2;
        update(2*nodeInd, st, mid, pos, x);
        update(2*nodeInd+1, mid+1, en, pos, x);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    // return the first id with maxi >= x
    int query(int nodeInd, int st, int en, int x){
        if(tree[nodeInd].maxi < x) return -1;
        if(st==en) {
            update(1, 0, n-1, st, x);
            return st;
        };

        // follow the child with maxi >= x
        int mid = (st+en)/2;
        if(tree[2*nodeInd].maxi >= x) return query(2*nodeInd, st, mid, x);
        else return query(2*nodeInd+1, mid+1, en, x);
    }

public:
    segmentTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    int queryID(int x){
        return query(1, 0, n-1, x);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // build segment tree to maintain max in a range
    segmentTree segTree(arr);

    while(q--){
        int x; cin>>x;
        // update first i elem to x
        cout << segTree.queryID(x)+1 << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}