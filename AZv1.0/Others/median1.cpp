#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(ll x, vector<ll> arr){ // count number of subarray with sum<=x
   int n = arr.size();
   
   ll cnt = 0;
   ll currSum = 0;
   ll start = 0;
   ll current = 0;
   while(current<n){
       currSum+=arr[current];
       while(start<=current and currSum>x){
           currSum-=arr[start];
           start++;
       }
       cnt+=(current-start+1);
       current++;

   }
   return cnt;
}

void solve(){
    int n; cin>>n;
    vector<ll> a(n);
    // vector<ll> pre(n);
    ll l=0, r=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        r+=a[i];
    }

    ll ans=-1;  // ?
    ll median = (n*(n+1))/2;
    median = (median+1)/2;

    while(l<=r){
        ll mid = (l+r)/2;
        if(func(mid, a) >= median){
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}