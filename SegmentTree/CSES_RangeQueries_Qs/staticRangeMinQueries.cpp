#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Given an array of n integers, your task is to process q queries of the form: what is the minimum value in range [a,b]?

void solve() {
    int n, q; cin>>n>>q;

    // Prefix Sum
    vector<ll> pre(n);
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        pre[i] = (i==0 ? x : pre[i-1]+x);
    }
    
    while(q--){
        int a, b; cin>>a>>b;
        a--; b--;   // 0-indexed
        cout << pre[b] - (a==0 ? 0 : pre[a-1]) << "\n"; 
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}