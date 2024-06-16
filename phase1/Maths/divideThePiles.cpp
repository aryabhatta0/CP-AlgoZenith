// https://maang.in/problems/Divide-the-Piles-67?resourceUrl=cs99-cp510-pl3424-rs67
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    // int a[n];
    int x;

    // gcd of each should be >=2
    int gcd=0;      // gcd(a, 0) = a
    for(int i=0; i<n; i++) {
        cin>>x;
        gcd = __gcd(gcd, x);
    }

    if(gcd>=2) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}