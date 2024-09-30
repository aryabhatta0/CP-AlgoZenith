#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;

    int a[n];
    for(int i=0; i<n; i++) a[i]=i+1;

    do {
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
    }  
    while(next_permutation(a, a+n));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}