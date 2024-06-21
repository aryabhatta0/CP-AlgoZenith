#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* 3 things:
 * apply correction     - update node's property while push
 * push()               - push lazy down to children
 * lazy merge           - merge two lazy
*/

struct node {
    int sum;
    int lazy; // lazy sum for lazy propagation

    node(int v = 0) {
        sum=v;
        lazy=0;
    }
};

// we merge the nodes that are not lazy
node merge(node a, node b) {
    return node(a.sum + b.sum);
}

class LazySegmentTree {
private:
    int n;
    vector<node> tree;

    // correct lazy at a node.
    // clear lazy. push it down.
    void push(int v, int st, int en) {
        /* if there is a lazy, apply and push down */

        if (tree[v].lazy != 0) {
            // apply logic
            tree[v].sum += (en - st + 1) * tree[v].lazy;
            
            // push lazy down if not leaf
            if (st != en) {
                // merge logic
                tree[v * 2].lazy += tree[v].lazy;
                tree[v * 2 + 1].lazy += tree[v].lazy;
            }
            // Unmark lazy
            tree[v].lazy = 0;
        }
    }

    /* Rest of things remians same, just a push is added */

    void build(const std::vector<int>& arr, int v, int st, int en) {
        if (st == en) {
            tree[v] = node(arr[st]);
            return;
        } 

        int mid = (st + en) / 2;
        build(arr, v * 2, st, mid);
        build(arr, v * 2 + 1, mid + 1, en);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    // each range can be broken into O(logN) nodes!
    void update_range(int v, int st, int en, int l, int r, int addend) {
        push(v, st, en);
        if(r<st || en<l) return;
        
        if(l<=st && en<=r){         // completely inside
            tree[v].lazy += addend;
            push(v, st, en);        // for correct merge in rec
            return;
        }

        int mid = (st + en) / 2;
        update_range(2*v, st, mid, l, r, addend);
        update_range(2*v+1, mid+1, en, l, r, addend);
        tree[v] = merge(tree[2*v], tree[2*v+1]);
    }

    node query_range(int v, int st, int en, int l, int r) {
        push(v, st, en);
        if (r < st || en < l) return node();        // out of range
        if (l <= st && en <= r) return tree[v];     // segment completely in range

        int mid = (st + en) / 2;
        return merge(query_range(2*v, st, mid, l, r) , query_range(2*v+1, mid+1, en, l, r));
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update_range(int l, int r, int addend) {
        update_range(1, 0, n - 1, l, r, addend);
    }

    node query_range(int l, int r) {
        return query_range(1, 0, n - 1, l, r);
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 3, -2, 8, -7};
    LazySegmentTree segtree(arr);

    cout << "Initial range query (0, 4): " << segtree.query_range(0, 4).sum << endl;

    segtree.update_range(1, 3, 5);
    cout << "After updating range (1, 3) by adding 5:" << endl;
    cout << "Range query (0, 4): " << segtree.query_range(0, 4).sum << endl;
    cout << "Range query (1, 1): " << segtree.query_range(1, 1).sum << endl;

    return 0;
}
