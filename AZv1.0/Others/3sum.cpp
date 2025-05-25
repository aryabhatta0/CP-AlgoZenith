#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; ll target; 
    cin>>n; cin>>target;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    // if(n<3){
    //     cout << "0\n";
    //     return;
    // }
    sort(a, a+n);

    ll ans=INT_MAX;
    for(int i=0; i<n-2; i++){
        int l=i+1, r=n-1;

        while(l<r){
            ll curr = a[l]+a[r]+a[i];
            // cout << "i=" << i << " l=" << l << " r=" << r << " => " << abs(target-curr) << "\n";
            ans = min(ans, abs(target-curr));
            if(ans==0) break;

            if(curr<target) l++;
            else r--;
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