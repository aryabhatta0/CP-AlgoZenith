// https://maang.in/problems/Subarray-Sum-Queries-404?resourceUrl=cs78-cp492-pl3320-rs404
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Debug:
 WA => first check indexing!
*/

struct node {
    ll msum;   // max subarr sum
    ll lsum;   // prefix sum
    ll rsum;   // suffix sum
    ll totSum; // range sum
    node(int n=0){      // n is the leaf node val
        totSum=n;

        n= max(0, n);   // if -ve val
        msum=n; lsum=n; rsum=n;
    }
};

node merge(node a, node b){
    node c;
    c.msum = max({a.msum, b.msum, a.rsum+b.lsum});
    c.lsum = max(a.lsum, a.totSum + b.lsum);
    c.rsum = max(b.rsum, b.totSum + a.rsum);
    c.totSum = a.totSum + b.totSum;
    return c;
}

class segmentTree {
private:
    int n;
    vector<node> tree;

    void build(vector<int>& arr, int nodeInd, int st, int en){
        if(st==en){
            // leaf node
            tree[nodeInd] = node(arr[st]);
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*nodeInd, st, mid);
        build(arr, 2*nodeInd+1, mid+1, en);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

    void update(int nodeInd, int st, int en, int pos, int x){
        if(pos<st || pos>en) return;
        if(st==en){
            // leaf node
            tree[nodeInd] = node(x);
            return;
        }

        int mid = (st+en)/2;
        update(2*nodeInd, st, mid, pos, x);
        update(2*nodeInd+1, mid+1, en, pos, x);
        tree[nodeInd] = merge(tree[2*nodeInd], tree[2*nodeInd+1]);
    }

public:
    segmentTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    ll query(int k, int x){
        update(1, 0, n-1, k, x);
        // return getSubarrSum(1, 0, n-1);
        return tree[1].msum;     // range is full array
    }
};

void solve(){
    int n, m; cin>>n>>m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    segmentTree segTree(arr);

    while(m--){
        int k, x; cin>>k>>x;
        k--;
        // update and return maxSubArr sum
        cout << segTree.query(k, x) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}