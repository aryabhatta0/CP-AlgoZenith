// https://maang.in/problems/Consecutive-one-44?resourceUrl=cs99-cp512-pl3461-rs44
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// check: if a contiguoes one subarr of len x is possible
// check for each starting index - O(n)
// monotonicity ? if x _/, x-1 also _/ - find optimal x

bool check(int x, vector<int> a, int n, int k){

    int cnt=0;
    for(int i=0; i<x; i++){
        if(a[i]==0) cnt++;
    }
    if(cnt <= k) return 1;

    for(int i=1; i <= n-x; i++){
        if(a[i-1]==0) cnt--;
        if(a[i+x-1]==0) cnt++;  // x len starting at i
        if(cnt <= k) return 1;
    }
    // for(int i=x; i<n; i++){
    //     if(a[i-x]==0) cnt--;
    //     if(a[i]==0) cnt++;
    //     if(cnt <= k) return 1;
    // }
    return 0;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int lo=k, hi=n;
    int ans=lo;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid, arr, n, k)){
            ans=mid;
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}