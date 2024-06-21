#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Variation of lec_appl4Q.cpp:
 2 types of problem:
    1. p[i]: no. of person taller and in front of ith person in final order
        - first place the person at last

    2. p[i]: no. of person taller and in front of person-i (curr order 1...N)
        - first place the smallest person at their appropriate place

 Dry run an example, to get the intuition always!
*/

// segment tree that supports insert, remove, and findKth
class orderedSet {
    int maxVal;
    // a node will store count of values in the range
    vector<int> tree;

    void insert(int nodeInd, int st, int en, int x){
        if(x<st || x>en) return;
        if(st==en) {
            tree[nodeInd]=1;    // set: unique vals
            return;
        }

        int mid = (st+en)/2;
        insert(2*nodeInd, st, mid, x);
        insert(2*nodeInd+1, mid+1, en, x);
        tree[nodeInd] = tree[2*nodeInd] + tree[2*nodeInd+1];
    }

    void remove(int nodeInd, int st, int en, int x){
        if(x<st || x>en) return;
        if(st==en) {
            tree[nodeInd]=0;  
            return;
        }

        int mid = (st+en)/2;
        remove(2*nodeInd, st, mid, x);
        remove(2*nodeInd+1, mid+1, en, x);
        tree[nodeInd] = tree[2*nodeInd] + tree[2*nodeInd+1];
    }

    // return kth smallest element
    int findKth(int nodeInd, int st, int en, int k){
        if(st==en) return st;

        int mid = (st+en)/2;
        if(tree[2*nodeInd]>=k) return findKth(2*nodeInd, st, mid, k);
        else return findKth(2*nodeInd+1, mid+1, en, k-tree[2*nodeInd]);
    }
    

public:
    // tree is being built over [1, maxVal]
    orderedSet(int limit=1e5){
        maxVal = limit;
        tree.resize(4*maxVal, 0);
    }

    void insert(int x){
        insert(1, 0, maxVal, x);
    }
    void remove(int x){
        remove(1, 0, maxVal, x);
    }
    int findKth(int k){
        return findKth(1, 0, maxVal, k);
    }

};

void solve(){
    int n; cin>>n;

    // place smallest height person first
    // build tree over 1 2 3 .... N
    // find (p+1)th smallest place for smallest height
    // remove place i.e, mark occupied

    map<int, int> mp;   // {height, ind}

    orderedSet st(n+1);      // build tree over 0...N-1 available posns in queue
    for(int i=0; i<n; i++) {
        int h; cin>>h;
        mp[h]=i;
        st.insert(i);
    }

    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    
    vector<int> res(n);
    for(auto it: mp){
        // smallest height. find appropriate place for it
        int ind = st.findKth(p[it.second]+1);
        res[ind] = it.second;
        st.remove(ind);
    }

    for(int i=0; i<n; i++) cout<<res[i]+1<<" ";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}