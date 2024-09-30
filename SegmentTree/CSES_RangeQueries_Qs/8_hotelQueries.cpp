#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// make a seg tree to find max of ranges
// and explore a sub-range accordingly

class segmentTree {
    int n;
    vector<ll> tree;

    void build(vector<int>& arr, int node, int st, int en) {
        if(st==en){
            tree[node] = arr[st];
            return;
        }

        int mid = (st+en)/2;
        build(arr, 2*node+1, st, mid);
        build(arr, 2*node+2, mid+1, en);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    // void update( ) {
    // }

    int query(int node, int st, int en, int req){
        if(tree[node] < req) return -1;

        if(st==en){
            // update bhi yahi kar do
            tree[node] -= req;
            return st;
        }

        int mid = (st+en)/2;
        int ans;
        if(tree[2*node+1] >= req) ans = query(2*node+1, st, mid, req);
        else ans = query(2*node+2, mid+1, en, req);

        // update bhi yahi kar do
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
        return ans;
    }

public:
    segmentTree(vector<int>& hotels){
        n = hotels.size();
        tree.resize(4*n);
        build(hotels, 0, 0, n-1);
    }

    // assign a hotel based on 'room' req
    int query(int room){
        // 0-indexed
        return 1 + query(0, 0, n-1, room);
    }

};

void solve() {
    int n, m; cin>>n>>m;
    vector<int> hotels(n);
    for(int i=0; i<n; i++) cin>>hotels[i];
    
    segmentTree segtree(hotels);

    // query rooms
    for(int i=0; i<m; i++) {
        int rooms; cin>>rooms;
        cout << segtree.query(rooms) << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}