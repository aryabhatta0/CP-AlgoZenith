// https://maang.in/problems/Count-the-Pairs-396?resourceUrl=cs99-cp510-pl3446-rs396

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// ToDo: Tutorial says u can also implement this using two pointers, how?

void solve(){
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    // A[j] <= X-A[i]
    // upper_bound(X-A[i]) - A[0]

    sort(a.begin(), a.end());
    ll cnt=0;
    for(int i=0; i<n; i++){
        int tar = x - a[i];
        int ind = upper_bound(a.begin(), a.end(), tar) - a.begin();
        if(ind-1 >= i) cnt+=ind-1;  // i j can't be the same isiliye exclude one case
        else cnt+=ind;
    }
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}