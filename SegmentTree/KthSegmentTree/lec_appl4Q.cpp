#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Question:
    there are n persons numbered 0.....n-1
    h[i]: height of ith person
    there is a order they've to stand in a row
    p[i]: no. of persons taller in front of person at ith posn
    Find the correct order.
*/

/* !!!
 Notice how this p[i] is different from orderOfHeights.cpp p[i]
 there, p[i] = no. of persons taller in front of ith person 
*/

// at each i, there will be p[i] taller elements in [0,i-1]
// at n-1, there will be p[n-1] taller elem in [0, n-2]
// therefore (p[n-1]+1)th largest elem will be at n-1
// remove placed elem and contnue
// HINT: Place persons from last

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

    // return kth largest element
    int findKth(int nodeInd, int st, int en, int k){
        if(st==en) return st;

        int mid = (st+en)/2;
        if(tree[2*nodeInd+1]>=k) return findKth(2*nodeInd+1, mid+1, en, k);
        else return findKth(2*nodeInd, st, mid, k-tree[2*nodeInd+1]);
    }

public:
    // tree is being built over [1, maxVal]
    orderedSet(){
        maxVal = 1e5;
        tree.resize(4*maxVal, 0);
    }

    void insert(int x){
        insert(1, 1, maxVal, x);
    }
    void remove(int x){
        remove(1, 1, maxVal, x);
    }
    int findKth(int k){
        return findKth(1, 1, maxVal, k);
    }

};

void solve(){
    int n; cin>>n;
    // we need to sort h, but can't lose indices
    // heights are unique _/
    map<int, int> mp;   // {height, ind}

    orderedSet st;
    for(int i=1; i<=n; i++) {
        int h; cin>>h;
        st.insert(h);
        mp[h]=i;
    }

    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    
    vector<int> res(n);
    for(int i=n-1; i>=0; i--){
        int curHeight = st.findKth(p[i]+1);
        // cout << "pos" << i+1 << " , " << p[i]+1 << "thLargestVal => " << curHeight << "\n";
        res[i] = mp[curHeight];
        st.remove(curHeight);
    }

    for(int i=0; i<n; i++) cout<<res[i]<<" ";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}