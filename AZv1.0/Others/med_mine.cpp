#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// what is the fucking prb
// even func showing WA here 

// check if there exists (m+1)/2 elements <= mid in subarray scores array
bool check(ll mid, vector<ll> &pre){
    int n = pre.size();
    ll m = (n*(n+1))/2;
    ll cnt=0;

    int tail=0, head=-1;
    while(tail<n){
        while(head<n-1 && pre[head+1]-(tail==0?0:pre[tail-1]) <= mid) 
            head++;
        cnt += head-tail+1;
        tail++;
        if(tail>head) head=tail-1;

        // if(cnt>=(m+1)/2 && pre[head]-pre[tail-1]==mid) 
        if(cnt>=(m+1)/2) 
            return true;
    }
    return false;
}

ll func(ll x, vector<ll> arr){ // count number of subarray with sum<=x
   int n = arr.size();
//    ll m = (n*(n+1))/2;
//    m = (m+1)/2;
   
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
       
    //    if(cnt>=(m+1)/2) 
    //         return true;
   }
   return cnt;
}

void solve(){
    int n; cin>>n;
    vector<ll> a(n);
    vector<ll> pre(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(i==0) pre[i] = a[i];
        else pre[i] = pre[i-1] + a[i];
    }

    // cout << "pre: ";
    // for(int i=0; i<n; i++) cout<<pre[i]<<" ";
    // cout<<"\n";

    // find median of array having all subarrays scores
    // median = (n+1)/2 th element
    // subarray score(i,j) = pre[j] - pre[i-1] => sum(i=i+1,i+2,3,...,j)

    // ll l=*min_element(a.begin(), a.end());
    ll l=0;
    ll r=pre[n-1];
    ll ans=-1;  // ?

    ll med = (n*(n+1))/2;
    med = (med+1)/2;
    while(l<=r){
        ll mid = (l+r)/2;
        // if(check(mid, pre)){
        if(func(mid, a) >= med){
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