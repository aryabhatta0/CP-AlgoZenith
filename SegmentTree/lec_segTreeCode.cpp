// SegmentTree/evenAndOddQueries.cpp
// Check this for more general implementation

#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Range sum on an array with dynamic update => segment tree
// A segment tree is a binary tree where each node represents a segment (or a range) of the array.

/* Segment Tree:
 - tree[4*n]
 - build(arr, node, st, en)
 - update(node, st, en, idx, val)
 - rangeSum(node, st, en, l, r)

 * {node, st, en} = {1, 0, n-1} are the starting node ✨

 * The tree is linearied using an array tree[4n]
 * Each node of the tree represents some range [st, en] (segment of array)
 * If node indexing starts from 1, the indices of child nodes are 2*node & 2*node+1
 * If node indexing starts from 0, the indices of child nodes are 2*node+1 & 2*node+2
 * We use recursion to go into child nodes and using the merging idea to do all the 3 tasks.
*/

// my implementation using class
class SegmentTree {
private:
    vector<ll> tree;
    int n;

    // Build the segment tree
    // each node represents a range [st, en] in tree
    void build(const vector<int>& arr,int node, int st, int en){
        // if it's a leaf node - base case
        if(st==en){
            tree[node] = arr[st];
            return;
        }

        // building children - diving range into 2 halves
        // the node_ind for childs will be 2*node & 2*node+1
        int mid = (st+en)/2;
        build(arr, 2*node, st, mid);
        build(arr, 2*node+1, mid+1, en);

        // each node will be the agregates of their child nodes
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // update the segTree for value updation at idx in orig array
    void update(int node, int st, int en, int idx, int val){
        // if idx not in [st, en]
        if(idx < st || idx > en) return;

        // if leaf node
        if(st==en) {
            tree[node] = val;
            return;
        }

        // go to appropriate child
        int mid = (st+en)/2;
        if(idx<=mid) update(2*node, st, mid, idx, val);
        else update(2*node+1, mid+1, en, idx, val);

        // update curr node
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    ll rangeSum(int node, int st, int en, int l, int r){
        // if [l,r] not in [st, en] or,
        // if [st, en] not in [l,r]
        if(en<l || r<st) return 0;

        // if [st, en] in [l,r]
        if(l<=st && en<=r){
            return tree[node];
        }

        // childs
        int mid = (st+en)/2;
        return rangeSum(2*node, st, mid, l, r) + rangeSum(2*node+1, mid+1, en, l, r);
    }

public:
    SegmentTree(int n){
        this->n=n;
        tree.resize(4*n, 0);
    }
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    // use cases - helps better in treating segTree as black box 
    void update(int idx, int val){
        update(1, 0, n-1, idx, val);
    }
    ll rangeSum(int l, int r){
        return rangeSum(1, 0, n-1, l, r);
    }

};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    SegmentTree segTree(arr);
    while(q--){
        int ch, i, j; cin>>ch>>i>>j;
        // arr in segTree are 0-indexed
        if(ch==1) segTree.update(i-1, j);
        else cout << segTree.rangeSum(i-1, j-1) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}