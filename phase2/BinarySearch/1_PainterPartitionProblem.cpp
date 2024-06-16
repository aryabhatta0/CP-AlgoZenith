// https://maang.in/problems/Famous-Painter-Partition-Problem-472?resourceUrl=cs99-cp512-pl3460-rs472
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// bS on ans is about.. 
// can we define a check() that separates values before and after optimal ans - Monotone space?

bool check(vector<int> a, ll t, int n, int k){
    ll curr_sum=0;
    for(int i=0; i<n; i++){
        if(curr_sum+a[i] <= t){
            curr_sum+=a[i];
        } else {
            k--;
            if(k<=0) return 0;
            curr_sum=a[i];
            // i--;
        }
    }

    return 1;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> length(n);
    ll lo=0, hi=0;
    for(int i=0; i<n; i++) {
        cin>>length[i];
        hi+=length[i];
        lo = max(lo, 1LL*length[i]);
    }

    ll ans=-1;
    while(lo<=hi){
        ll mid = lo + (hi-lo)/2;

        // check if it's possible to get the work done in mid time
        // look at monotonous nature of ans - mid+1 would also be possible

        // cout << "check for " << mid << "s " << check(length, mid, n, k) << "\n";
        if(check(length, mid, n, k)){
            hi=mid-1;
            ans=mid;
        } else{
            lo=mid+1;
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