// https://maang.in/problems/Bitonic-Array-107?resourceUrl=cs99-cp512-pl3459-rs107
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, q; cin>>n>>q;
    // vector<int> a(n);
    unordered_map<int, vector<int>> mp;   // val, ind
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        mp[x].push_back(i+1);
    }

    int k;
    while(q--){
        cin>>k;
        for(auto it: mp[k]){
            cout << it << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}