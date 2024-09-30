// https://maang.in/problems/Rebuild-Original-Array-87?resourceUrl=cs117-cp540-pl3642-rs87&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: Given a subset sum array of size 2^N (N<=15), rebuild the original array.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Idea: The smallest nonzero elem of array will be the first element of original array
// Build on that, delete all the subset sums possible in array already built from given array
void solve(){
    int n; cin>>n;
    ll sz= pow(2, n);
    multiset<ll> mst;
    ll x;
    for(int i=0; i<sz; i++) {
        cin>>x; mst.insert(x);
    }
    // erase 0
    mst.erase(mst.begin());

    vector<ll> ans;
    vector<ll> currSubsetSum;
    while(!mst.empty()) {
        ll newElement = *mst.begin();
        ans.push_back(newElement);
        mst.erase(mst.begin());

        int oldSize = currSubsetSum.size();
        for(ll i=0; i<oldSize; i++) {
            currSubsetSum.push_back(currSubsetSum[i] + newElement);
            mst.erase(mst.find(currSubsetSum.back()));
        }
        currSubsetSum.push_back(newElement);
    }
    
    for(auto it: ans) cout << it << " ";
    cout<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}