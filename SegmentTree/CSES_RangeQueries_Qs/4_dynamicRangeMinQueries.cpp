#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// The only difference here that RangeSum queries would be in - MERGE LOGIC

class segmentTree {
    int n;
    vector<ll> tree;

    // root is at 0
    void build(vector<int>& arr, int node, int st, int en){
        // base case
        if(st==en){
            tree[node] = arr[st];
            return;
        }

        // build children
        int mid = (st+en)/2;
        build(arr, 2*node+1, st, mid);
        build(arr, 2*node+2, mid+1, en);

        // merge childs
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    void update(int node, int st, int en, int ind, int val){
        // safe check - if ind out of range
        if(ind<st || ind > en) return;

        // base case
        if(st==en){
            tree[node] = val;
            return;
        }

        // look into children
        int mid = (st+en)/2;
        if(ind<=mid) update(2*node+1, st, mid, ind, val);
        else update(2*node+2, mid+1, en, ind, val);

        // update par
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    // return contribution of [st,en] in min of range [l,r]
    ll rangeMin(int node, int st, int en, int l, int r){
        // outside
        if(en<l || st>r) return 1e9;

        // if totally inside
        if(st >= l && en <= r) return tree[node];

        // childrens
        int mid = (st+en)/2;
        return min(rangeMin(2*node+1, st, mid, l, r), rangeMin(2*node+2, mid+1, en, l, r));
    }

public:
    segmentTree (int n, vector<int>& arr){
        this->n=n;
        tree.resize(4*n);
        build(arr, 0, 0, n-1);
    }

    void update(int k, int u){
        update(0, 0, n-1, k, u);
    }

    ll rangeMin(int a, int b) {
        return rangeMin(0, 0, n-1, a, b);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    segmentTree segTree(n, arr);
    while(q--){
        int ch, x, y;
        cin>>ch>>x>>y;
        // we've 0 indexed values
        if(ch==1) segTree.update(x-1, y);
        else cout << segTree.rangeMin(x-1, y-1) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}