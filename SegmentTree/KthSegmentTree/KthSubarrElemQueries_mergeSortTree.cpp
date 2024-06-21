// LittleToughQueries.cpp
// Find kth smallest element in [l,r] subarray queries
// queries: l, r, k
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Merge Sort Tree Idea: 
 * Gives no. of elements <= x in any subarray [l,r]
 * build(): stores all nodes in range in sorted order - O(NlogN)
 * 
 * query(l, r, x): 
 * remember queries should be O(logN) max
 * break range into O(logN) nodes and use upper_bound to find numElements <= x for each node
 */

// find kth smallest elem in query subarr [l, r]
// no updates? we can build Tree in O(NlogN) and answer queries in O(logN)
// Let's store all vals in the range for a node!

// Answering queries?
// Find kth smallest elem in range?
// bS on ans - we can find no. of elements <= x in a range

struct node {
    vector<int> vec;
    node(const vector<int>& v= vector<int>()){
        vec = v;
    }
};

// O(N) - better merge
vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            result.push_back(vec1[i]);
            ++i;
        } else {
            result.push_back(vec2[j]);
            ++j;
        }
    }
    // Store remaining elements
    while (i < vec1.size()) {
        result.push_back(vec1[i]);
        ++i;
    }
    while (j < vec2.size()) {
        result.push_back(vec2[j]);
        ++j;
    }
    return result;
}

node merge(node a, node b){
    return node(mergeSortedVectors(a.vec, b.vec));
    
    // vector<int> res;
    // for(auto it: a.vec) res.push_back(it);
    // for(auto it: b.vec) res.push_back(it);
    // sort(res.begin(), res.end());
    // return node(res);
}

// merge sort tree
class mergeSortTree {
    int n; 
    vector<node> tree;

    // O(NlogN)
    void build(vector<int>& arr, int nodeId, int st, int en){
        if(st==en){
            tree[nodeId] = vector<int>(1, arr[st]);
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*nodeId, st, mid);
        build(arr, 2*nodeId+1, mid+1, en);
        tree[nodeId] = merge(tree[2*nodeId], tree[2*nodeId+1]);
    }

    /**prb specific: O(NlogN) perquery, 
     * we can't directly merge node like this, make the timecomplexity O(logN)*/
    // node query(int nodeId, int st, int en, int l, int r, int k){
    //     // break (l,r) into log(N) nodes
    //     // outside
    //     if(en<l || r<st) return node();
    //     // inside
    //     if(l<=st && en<=r){
    //         return tree[nodeId];
    //     }

    //     int mid = (st+en)/2;
    //     return merge(query(2*nodeId, st, mid, l, r, k), query(2*nodeId+1, mid+1, en, l, r, k));
    // }

    // returns the num of elements <=x in [l,r] subarr
    int query(int nodeId, int st, int en, int l, int r, int x){
        if(en<l || r<st) return 0;
        if(l<=st && en<=r){
            // totally inside - return this nodeId's contribution
            // return numElements <=x in [st, en]
            return upper_bound(tree[nodeId].vec.begin(), tree[nodeId].vec.end(), x) - tree[nodeId].vec.begin();
        }

        int mid = (st+en)/2;
        return query(2*nodeId, st, mid, l, r, x) + query(2*nodeId+1, mid+1, en, l, r, x);
    }

public: 
    mergeSortTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    // returns the num of elements <=x in [l,r] subarr
    int query(int l, int r, int x){
        return query(1, 0, n-1, l, r, x);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    mergeSortTree segTree(a);

    while(q--){
        int l, r, k; cin>>l>>r>>k;
        // cout << segTree.query(l-1, r-1, k-1) << "\n";
        l--; r--; 

        // bs on ans
        int lo=1, hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            // query gives the no. of elements <=mid in [l,r]
            // monotonic space:   1 2 3 ..... [k] k k k
            if(segTree.query(l, r, mid) >= k){
                ans=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
        cout << ans << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}