// https://cses.fi/problemset/task/1651
// https://maang.in/problems/Range-Queries-II-402?resourceUrl=cs78-cp492-pl3320-rs402
// rangeQueries2 / rangeUpdateQueries

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class segmentTree {
private:
    int n;
    // tree consists of node structures that are int denoting range sum here
    vector<ll> tree;

    // build isn't necessary here

    // inc val at idx by val
    void update(int node, int st, int en, int idx, int val){
        if(idx<st || en<idx) return;
        if(st==en) {
            tree[node] += val;
            return;
        }

        int mid = (st+en)/2;
        update(2*node, st, mid, idx, val);
        update(2*node+1, mid+1, en, idx, val);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    ll querySum(int node, int st, int en, int l, int r){
        // bahar
        if(en<l || r<st) return 0;
        // andar
        if(l<=st && en<=r) return tree[node];

        int mid = (st+en)/2;
        return querySum(2*node, st, mid, l, r) + querySum(2*node+1, mid+1, en, l, r);
    }

public:
    segmentTree(int n){
        this->n=n;
        tree.resize(4*n, 0);
        // build(1, 0, n-1);
    }

    void update(int idx, int val){
        update(1, 0, n-1, idx, val);
    }
    ll query(int l, int r){
        return querySum(1, 0, n-1, l, r);
    }

};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    segmentTree segTree(n);

    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int a, b, u; cin>>a>>b>>u;
            a--; b--;

            // partial sum idea
            segTree.update(a, u);
            segTree.update(b+1, -u);
        } else {
            int k; cin>>k; k--;
            // query sum (0,k) will give the prefix sum of k that denotes the total increment at posn k
            cout << segTree.query(0, k) + x[k] << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}