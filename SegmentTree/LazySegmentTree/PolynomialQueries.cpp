// https://cses.fi/problemset/task/1736

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Initial Incomplete Thought:
    - at each node, we were storing inc of 1st elem before. The rest'd inc with a common diff of 1.
    - lazy-merge: (2,1) -> (3,1) : (5,2) on child, so the cd of seq to apply can also be changed
    - Store {a, d} for each node. Applying an AP on ranges!
*/

// Good Q: Intuition aane ke baad bhi ni ban payega
// REMEMBER: An AP can be applied on ranges using LazySegTree

using ap = pair<ll, ll>;      // {a, d}

/*
    1. Lazy mein rakhein kya?      : it's mostly what's given to apply in Q
    2. Lazy-merge   : upar se jo aaya, tab?     : * 2 AP's can be superimposed
    3. apply        : apply lazy on node to correct node's prop
    4. push_down    : (a,d) , ((mid+1)th term, d)
*/

struct node {
    ll sum; 
    ap lazy;
    node(ll s=0){
        sum=s; lazy={0,0};
    }
};

node merge(node a, node b){
    return node(a.sum+b.sum);
}

class lazySegTree {
private:
    int n;
    vector<node> tree;

    inline ll getAPSum(ap curr, ll n){
        ll a = curr.first, d = curr.second;
        return (n * (2*a + (n-1)*d)) /2;
    }

    inline ap getNth(ap curr, int n){
        return {curr.first + (n-1)*curr.second, curr.second};
    }

    void push_down(ap curr, int child){
        tree[child].lazy.first += curr.first;
        tree[child].lazy.second += curr.second;
    }

    // lazy-merge: (2,1) -> (3,1) : (5,2) on child, so the common difference of seq to apply can also be changed
    void push(int nodeInd, int st, int en){
        if(tree[nodeInd].lazy!=make_pair(0LL,0LL)){
            // apply
            tree[nodeInd].sum += getAPSum(tree[nodeInd].lazy, en-st+1);

            // push_down
            if(st!=en){
                int mid = (st+en)/2;
                push_down(tree[nodeInd].lazy, 2*nodeInd);

                // potential mistake :)
                int m = mid-st+1;   // no. of elems in 1st child
                push_down(getNth(tree[nodeInd].lazy, m+1), 2*nodeInd+1);
            }

            tree[nodeInd].lazy = {0,0};
        }
    }

    void build(vector<int>& arr, int nodeInd, int st, int en){
        if(st==en){
            tree[nodeInd] = node(arr[st]);
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*nodeInd, st, mid);
        build(arr, 2*nodeInd+1, mid+1, en);

        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    /**  each range can be broken into logN nodes */
    // (l,r) & (a,d) are the query. We iterate over (st, en) using recursion and update if completely insise.
    // coz basically we've to find logN such (st,en) that can make (l,r)
    // and rather than updating those logN nodes, we set them lazy
    void update_range(int nodeInd, int st, int en, int l, int r, ll a, ll d){
        push(nodeInd, st, en);
        if(r<st || en<l) return;

        if(l<=st && en<=r){
            // completely inside
            // tree[nodeInd].lazy = make_pair(a, d);
            tree[nodeInd].lazy = make_pair(st-l+1, d);
            push(nodeInd, st, en);
            return;
        }

        int mid = (st+en)/2;
        update_range(2*nodeInd, st, mid, l, r, a, d);
        update_range(2*nodeInd+1, mid+1, en, l, r, a, d);       // ?!!
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    node query(int nodeInd, int st, int en, int l, int r){
        push(nodeInd, st, en);
        // out of range
        if (r < st || en < l) return node();
        // segment completely in range
        if (l <= st && en <= r) 
            return tree[nodeInd];

        int mid = (st+en)/2;
        return merge(query(2*nodeInd, st, mid, l, r) , query(2*nodeInd+1, mid+1, en, l, r));
    }

public:
    lazySegTree(vector<int>& arr){
        n= arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void update_range(int l, int r, int a, int d){
        update_range(1, 0, n-1, l, r, a, d);
    }
    ll querySum(int l, int r){
        return query(1, 0, n-1, l, r).sum;
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    lazySegTree segTree(t);

    while(q--){
        int ch, a, b; cin>>ch>>a>>b;
        a--; b--;
        // init_ap = {1,1}
        if(ch==1) segTree.update_range(a, b, 1, 1);
        else cout << segTree.querySum(a, b) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}