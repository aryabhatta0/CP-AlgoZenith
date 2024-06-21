// https://cses.fi/problemset/task/1650/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 This problem could have been solved using Prefix Sum
 * XOR in range follows Prefix Sum idea
 * Mostly static or no updation could be solved without SegTree
 * Range Query Update => SegTree
*/

// sth to do over ranges in array => segTree
// it represents each node as a range, and divides it into equal halves for child 

class XORSegmentTree {
    vector<ll> tree;
    int n;

    void build(vector<int>& arr, int node, int st, int en){
        if(st==en){
            tree[node] = arr[st];   // leaf node
            return;
        }

        // childs
        int mid = (st+en)/2;
        build(arr, 2*node, st, mid);
        build(arr, 2*node+1, mid+1, en);

        tree[node] = tree[2*node] ^ tree[2*node+1];
    }

    ll XORquery(int node, int st, int en, int l, int r){
        // base cases - 0 or tree[node]

        // if [st, en] not in [l,r]
        if(en < l || r < st) return 0;

        // if [st, en] totally in [l,r]
        if(l<=st && en<=r) return tree[node];

        // childs contribution to ans
        int mid = (st+en)/2;
        return XORquery(2*node, st, mid, l, r) ^ XORquery(2*node+1, mid+1, en, l, r); 
    }

public:
    XORSegmentTree(vector<int>& arr){
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    ll XORquery(int l, int r){
        return XORquery(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    XORSegmentTree segTree(arr);

    while(q--){
        int a, b; cin>>a>>b;
        cout << segTree.XORquery(a-1, b-1) << "\n";     // 0-ind
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}