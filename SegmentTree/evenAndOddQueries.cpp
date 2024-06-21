// https://maang.in/problems/Even-and-Odd-Queries-405?resourceUrl=cs78-cp492-pl3320-rs405
// Maintain count of even & odd no. for various ranges

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Just 3 changes:
 * Node Structure
 * Merge Logic
 * Leaf Value
*/

struct node {
    int even;
    int odd;
    node(int ev=0, int od=0){
        even=ev; odd=od;
    }
};

node merge(node a, node b){
    return node(a.even+b.even, a.odd+b.odd);
}

class segmentTree {
private:
    int n;
    vector<node> tree;

    void build(vector<int>& arr, int nodeInd, int st, int en){
        if(st==en){
            // leaf node
            if(arr[st]%2==0) tree[nodeInd] = node(1,0);
            else tree[nodeInd] = node(0,1); 
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*nodeInd, st, mid);
        build(arr, 2*nodeInd+1, mid+1, en);

        // merge logic
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    void update(int nodeInd, int st, int en, int idx, int val){
        if(idx<st || en<idx) return;
        if(st==en){
            if(val%2==0) tree[nodeInd] = node(1,0);
            else tree[nodeInd] = node(0,1); 
            return;
        }

        int mid = (st+en)/2;
        update(2*nodeInd, st, mid, idx, val);
        update(2*nodeInd+1, mid+1, en, idx, val);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    node query(int nodeInd, int st, int en, int l, int r){
        // out of range
        if (r < st || en < l) return node();
        // segment completely in range
        if (l <= st && en <= r) 
            return tree[nodeInd];

        int mid = (st+en)/2;
        return merge(query(2*nodeInd, st, mid, l, r) , query(2*nodeInd+1, mid+1, en, l, r));
    }

public:
    segmentTree(vector<int>& arr){
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int countEven(int l, int r) {
        node result = query(1, 0, n - 1, l, r);
        return result.even;
    }

    int countOdd(int l, int r) {
        node result = query(1, 0, n - 1, l, r);
        return result.odd;
    }
};

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    segmentTree segTree(a);

    int q; cin>>q;
    while(q--){
        int ch, x, y; cin>>ch>>x>>y;
        if(ch==0){
            x--;
            segTree.update(x, y);
        } else if(ch==1) {
            x--; y--;
            cout << segTree.countEven(x, y) << "\n";
        } else {
            x--; y--;
            cout << segTree.countOdd(x, y) << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}