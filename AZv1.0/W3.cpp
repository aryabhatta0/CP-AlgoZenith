#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);

    // calculate prefix sum
    ll p[n];
    p[0]=a[0];
    for(int i=1; i<n; i++)
        p[i]=p[i-1]+a[i];

    while(q--){
        int m; cin>>m;
        cout << upper_bound(p, p+n, m)-p << "\n";
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