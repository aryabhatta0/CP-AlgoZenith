// https://maang.in/problems/Buy-Maximum-Objects-I-75?resourceUrl=cs99-cp510-pl3436-rs75

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, m; cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a, a+n);
    int cnt=0;
    for(int i=0; i<n; i++){
        m-=a[i];
        if(m>=0) cnt++;
        else break;
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