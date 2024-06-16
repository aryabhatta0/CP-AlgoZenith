// STL Application Ideas 1
// https://maang.in/problems/Buy-Maximum-Objects-II-74?resourceUrl=cs99-cp510-pl3443-rs74
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy: Tryna do best thing that could be done at that time

void solve(){
    int n, q; cin>>n>>q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    sort(a.begin(), a.end());
    // prefix sum
    for(int i=1; i<n; i++) a[i] += a[i-1];

    int m;
    while(q--){
        cin>>m;
        int ans = upper_bound(a.begin(), a.end(), m) - a.begin();  // no. elements <= m 
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}