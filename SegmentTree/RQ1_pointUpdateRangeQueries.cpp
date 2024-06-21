// Check SegmentTree/lec_segTreeCode.cpp
// rangeQueries1 - std prb

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct segmentTree {
    int n;
    vector<ll> tree;    // we'll linearize segmentTree into an array
    vector<int> arr;      // the array

    segmentTree(int n){
        this->n=n;
        tree.resize(4*n);
        arr.resize(n);

        for(int i=0; i<n; i++) cin>>arr[i];
    }

    // ind: ind of tree node (tree array) denoting [l-r] range
    void build(int ind, int l, int r){
        // base case
        if(l==r){
            tree[ind] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        // build children
        // the indices of children are 2*ind and 2*ind+1
        build(2*ind, l, mid);
        build(2*ind+1, mid+1, r);

        tree[ind] = tree[2*ind] + tree[2*ind+1];
    }

    // update val at posn i to x
    void update(int ind, int l, int r, int i, int x){
        if(l==r){
            tree[ind] = x;    // leaf node
            arr[i] = x;
            return;
        }

        int mid = (l+r)/2;
        if(i <= mid) update(2*ind, l, mid, i, x);
        else update(2*ind+1, mid+1, r, i, x);

        // update current node in case children have been updated
        tree[ind] = tree[2*ind] + tree[2*ind+1];
    }

    ll rangeSum(int ind, int l, int r, int lq, int rq){
        // if not in range
        if(rq < l || r < lq) return 0;

        // if (l,r) completely inside (lq,rq)
        if(lq <= l && r <= rq) return tree[ind];

        int mid = (l+r)/2;
        return rangeSum(2*ind, l, mid, lq, rq) + rangeSum(2*ind+1, mid+1, r, lq, rq);
    }
};

void solve(){
    int n, q;
    cin>>n>>q;

    segmentTree segTree(n);
    segTree.build(1, 0, n-1); // Don't forget to build the tree

    while(q--){
        int ch, i, j; cin>>ch>>i>>j;
        if(ch==1)
            segTree.update(1, 0, n-1, i-1, j);
        else 
            cout << segTree.rangeSum(1, 0, n-1, i-1, j-1) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
