#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class segmentTree {
private:
    int n;
    vector<ll> tree;

    // inc by val
    void update(int node, int st, int en, int ind, int val){
        if(ind<st || en<ind) return;

        if(st==en){
            tree[node] += val;
            return;
        }

        // check children
        int mid = (st+en)/2;
        update(2*node+1, st, mid, ind, val);
        update(2*node+2, mid+1, en, ind, val);

        // update parent
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    ll rangeSum(int node, int st, int en, int l, int r){
        // outside
        if(en<l || st>r) return 0;

        // if [[st, in] completely inside
        if(l<=st && en<=r) return tree[node];

        // children
        int mid = (st+en)/2;
        return rangeSum(2*node+1, st, mid, l, r) + rangeSum(2*node+2, mid+1, en, l, r);
    }

public:
    segmentTree(int n){
        this->n=n;
        tree.resize(4*n, 0);
        // build(arr, 0, 0, n-1);   // no need to build
    }

    // inc val at ind by val
    void update(int ind, int val){
        update(0, 0, n-1, ind, val);
    }
    ll rangeSum(int l, int r){
        return rangeSum(0, 0, n-1, l, r);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    segmentTree segTree(n);
    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int a, b, u; cin>>a>>b>>u;
            a--; b--;

            /** partial sum idea */
            // add u at a
            segTree.update(a, u);
            // subtract u at b+1
            segTree.update(b+1, -u);
            // if (b+1 < n) segTree.update(b+1, -u);
        } else {
            int k; cin>>k;
            k--;
            cout << segTree.rangeSum(0, k) + arr[k] << "\n";
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}