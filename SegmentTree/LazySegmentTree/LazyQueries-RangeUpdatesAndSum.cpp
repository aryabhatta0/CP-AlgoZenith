// https://maang.in/problems/Lazy-Queries-407?resourceUrl=cs78-cp492-pl3322-rs407
// https://cses.fi/problemset/task/1735/

/*
Your task is to maintain an array of n values and efficiently process the following types of queries:
    Increase each value in range [a, b] by x.
    Set each value in range [a, b] to x.
    Calculate the sum of values in range [a, b].
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 2 lazys? Defining pushLazy logic becomes crucial!
// Look notes for intuition

struct node {
    ll sum;
    ll lazy_add, lazy_set;    // 2 types of update query 
    node(ll s=0){
        sum=s;
        lazy_add=0; lazy_set=0;
    }
};

// only non-lazy nodes gets merged
node merge(node a, node b){
    return node(a.sum+b.sum);
}

class segmentTree {
public:
    int n;
    vector<node> tree;

    void push_down(int curr, int child){
        if(tree[curr].lazy_set!=0){
            // doesn't matter if child is lazy_set or lazy_add
            tree[child].lazy_set = tree[curr].lazy_set;
            tree[child].lazy_add = 0;
        }
        else if(tree[curr].lazy_add!=0){
            if(tree[child].lazy_set!=0){
                tree[child].lazy_set += tree[curr].lazy_add;
                tree[child].lazy_add = 0;
            }
            else {
                tree[child].lazy_add += tree[curr].lazy_add;
                tree[child].lazy_set = 0;
            }
        }
    }

    // more intuitive
    void push(int nodeInd, int st, int en){
        if(!tree[nodeInd].lazy_add && !tree[nodeInd].lazy_set) return;

        if(st!=en){
            push_down(nodeInd, 2*nodeInd);
            push_down(nodeInd, 2*nodeInd+1);
        }

        // Can't both lazy_add & lazy_set be there for a node? No?
        // apply
        if(tree[nodeInd].lazy_add!=0){
            tree[nodeInd].sum += (en-st+1)*tree[nodeInd].lazy_add;
            tree[nodeInd].lazy_add = 0;
        }
        else if(tree[nodeInd].lazy_set!=0) {
            tree[nodeInd].sum = (en-st+1)*tree[nodeInd].lazy_set;
            tree[nodeInd].lazy_set = 0;
        }
    }

    // what is a node or its child has both lazy_add & lazy_set ?
    // order of applying ? - lazy_set has to be applied before lazy_add
    void push2(int nodeInd, int st, int en) {
        if (tree[nodeInd].lazy_set != 0) {
            tree[nodeInd].sum = tree[nodeInd].lazy_set * (en - st + 1);
            if (st != en) {
                tree[2 * nodeInd].lazy_set = tree[nodeInd].lazy_set;
                tree[2 * nodeInd + 1].lazy_set = tree[nodeInd].lazy_set;
                tree[2 * nodeInd].lazy_add = 0;
                tree[2 * nodeInd + 1].lazy_add = 0;
            }
            tree[nodeInd].lazy_set = 0;
        }

        if (tree[nodeInd].lazy_add != 0) {
            tree[nodeInd].sum += tree[nodeInd].lazy_add * (en - st + 1);
            if (st != en) {
                tree[2 * nodeInd].lazy_add += tree[nodeInd].lazy_add;
                tree[2 * nodeInd + 1].lazy_add += tree[nodeInd].lazy_add;
            }
            tree[nodeInd].lazy_add = 0;
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

    // each range can be broken into logN nodes
    void update_range(int nodeInd, int st, int en, int l, int r, int val, bool inc){
        push(nodeInd, st, en);
        if(r<st || en<l) return;

        // if(st==en)
        if(l<=st && en<=r){
            // completely inside
            if(inc) {
                // tree[nodeInd].lazy_add=val;
                tree[nodeInd].lazy_add+=val;
                // tree[nodeInd].lazy_set=0;      // one lazy overwrite others?
            }
            else {
                tree[nodeInd].lazy_set=val;
                tree[nodeInd].lazy_add=0;
            }
            push(nodeInd, st, en);
            return;
        }

        int mid = (st+en)/2;
        update_range(2*nodeInd, st, mid, l, r, val, inc);
        update_range(2*nodeInd+1, mid+1, en, l, r, val, inc);
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

// public:
    segmentTree(vector<int>& arr){
        n= arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    segmentTree segTree(t);

    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int a, b, x; cin>>a>>b>>x;
            segTree.update_range(1, 0, n-1, a-1, b-1, x, true);
        }
        else if(ch==2){
            int a, b, x; cin>>a>>b>>x;
            segTree.update_range(1, 0, n-1, a-1, b-1, x, false);
        } else {
            int a, b; cin>>a>>b;
            cout << segTree.query(1, 0, n-1, a-1, b-1).sum << "\n";
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}