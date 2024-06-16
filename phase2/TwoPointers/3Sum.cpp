// https://maang.in/problems/3-Sum-65?resourceUrl=cs99-cp512-pl3476-rs65
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// BS
void solve1(){
    int n; ll tar; 
    cin>>n>>tar;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    // O(n^2 logn) _/
    ll ans=LLONG_MAX;     // min abs diff
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll req = tar - a[i] - a[j];
            // find k so that diff = req - a[k] min
            // find elem closest to req
            int ind = lower_bound(a.begin()+j+1, a.end(), req) - a.begin();

            if(ind!=n) ans = min(ans, abs(req - a[ind]));
            if(ind-1>j) ans = min(ans, abs(req - a[ind-1]));
        }
    }
    cout << ans << "\n";
}

// 2ptr
void solve2(){
    int n; ll target; 
    cin>>n; cin>>target;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);

    // ll ans=abs(a[0]+a[1]+a[2]-target);
    // ll ans=INT_MAX; 
    ll ans=LLONG_MAX;
    for(int i=0; i<n; i++){
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
        solve2();
    }
    return 0;
}