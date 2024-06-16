// https://maang.in/problems/ClassRoom-471?resourceUrl=cs99-cp512-pl3462-rs471
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// check if there can be min x gap b/w any two student
// if x gap, x-1 also. monotonicity _/
bool check(int x, vector<int> a, int n, int k){
    int last=0;
    k--;    // a[0] par bitha diye
    if(k==0) return 1;

    for(int i=1; i<n; i++){
        if(a[i]-a[last] >= x){
            last=i;
            k--;
            if(k==0) return 1;
        }
    }

    if(k==0) return 1;
    return 0;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    int lo=0, hi=1e9;
    int ans=-1;
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