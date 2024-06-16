// https://maang.in/problems/Rotated-Sorted-Array-108?resourceUrl=cs99-cp512-pl3459-rs108
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // Monotone space: If a elem is >= a[0]
    // find first 0 occ then
    // except 1 2 3 4 5 , where ans=0
    int lo=0, hi=n-1;
    int ans=0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]>=a[0]){
            lo=mid+1;
        } else {
            hi=mid-1;
            ans=mid;
        }
    }
    cout << ans << "\n";
}

// without binary search - O(n)
// find first element with a[i]>a[i+1]
void solve_withoutBS(){
    int n; cin>>n;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int i;
    for(i=0; i<n; i++){
        if(i==n-1 && a[i]>a[0]){
            cout<< "0\n";
            return;
        }
        else if(a[i]>a[i+1]){
            cout<< i+1 << "\n";
            return;
        }
    }
    cout<<"0\n";   // if all elements are equal
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}