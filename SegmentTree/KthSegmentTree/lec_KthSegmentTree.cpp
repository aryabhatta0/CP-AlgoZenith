#include <bits/stdc++.h>
using namespace std;
#define ll long long

// segment tree that supports insert, remove, findKthSmallest, and findKthLargest
class orderedSet {
    int maxVal;
    // a node will store count of values in the range
    vector<int> tree;

    void insert(int nodeInd, int st, int en, int x){
        if(x < st || x > en) return;
        if(st == en) {
            tree[nodeInd] = 1;    // set: unique vals
            return;
        }

        int mid = (st + en) / 2;
        insert(2 * nodeInd, st, mid, x);
        insert(2 * nodeInd + 1, mid + 1, en, x);
        tree[nodeInd] = tree[2 * nodeInd] + tree[2 * nodeInd + 1];
    }

    void remove(int nodeInd, int st, int en, int x){
        if(x < st || x > en) return;
        if(st == en) {
            tree[nodeInd] = 0;  
            return;
        }

        int mid = (st + en) / 2;
        remove(2 * nodeInd, st, mid, x);
        remove(2 * nodeInd + 1, mid + 1, en, x);
        tree[nodeInd] = tree[2 * nodeInd] + tree[2 * nodeInd + 1];
    }

    // return kth smallest element
    int findKthSmallest(int nodeInd, int st, int en, int k){
        if(st == en) return st;

        int mid = (st + en) / 2;
        if(tree[2 * nodeInd] >= k) return findKthSmallest(2 * nodeInd, st, mid, k);
        else return findKthSmallest(2 * nodeInd + 1, mid + 1, en, k - tree[2 * nodeInd]);
    }

    // return kth largest element
    int findKthLargest(int nodeInd, int st, int en, int k){
        if(st == en) return st;

        int mid = (st + en) / 2;
        if(tree[2 * nodeInd + 1] >= k) return findKthLargest(2 * nodeInd + 1, mid + 1, en, k);
        else return findKthLargest(2 * nodeInd, st, mid, k - tree[2 * nodeInd + 1]);
    }

public:
    // tree is being built over [1, maxVal]
    orderedSet(int limit = 1e5) {
        maxVal = limit;
        tree.resize(4 * maxVal, 0);
    }

    void insert(int x) {
        insert(1, 0, maxVal, x);
    }
    void remove(int x) {
        remove(1, 0, maxVal, x);
    }
    int findKthSmallest(int k) {
        return findKthSmallest(1, 0, maxVal, k);
    }
    int findKthLargest(int k) {
        return findKthLargest(1, 0, maxVal, k);
    }
};


// Example usage
int main() {
    orderedSet oset; 

    oset.insert(10);
    oset.insert(20);
    oset.insert(30);
    oset.insert(40);
    oset.insert(50);

    cout << "2nd smallest: " << oset.findKthSmallest(2) << endl;  // Output: 20
    cout << "2nd largest: " << oset.findKthLargest(2) << endl;    // Output: 40

    oset.remove(20);
    oset.remove(50);

    cout << "2nd smallest after removal: " << oset.findKthSmallest(2) << endl;  // Output: 30
    cout << "2nd largest after removal: " << oset.findKthLargest(2) << endl;    // Output: 30

    return 0;
}
