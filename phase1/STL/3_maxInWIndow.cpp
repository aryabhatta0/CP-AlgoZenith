// https://maang.in/problems/Maximum-in-Window-77?resourceUrl=cs99-cp510-pl3445-rs77
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, k;
    cin>>n>>k;
    ll a[n];
    for(int i=0; i<n;i++)
        cin>>a[i];
    
    multiset<int> mt;
    for(int i=0; i<k; i++)
        mt.insert(a[i]);
    cout << *mt.rbegin() << " ";
    
    for(int i=1;i<=n-k;i++){
        mt.erase(mt.find(a[i-1]));
        mt.insert(a[i+k-1]);
    	cout << *mt.rbegin() << " ";   
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}