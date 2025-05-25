#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) a[i] = i+1;
    k--;    // 1st permutation is arr itself
    while(k--) {
        next_permutation(a.begin(), a.end());
        // for(int i=0; i<n; i++) cout<<a[i]<<" ";
        // cout<<"\n";
    }

    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}