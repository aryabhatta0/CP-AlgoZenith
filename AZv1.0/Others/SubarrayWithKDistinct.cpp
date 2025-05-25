// Given an array of N integers, find the number of subarrays with at most K distinct elements.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
	
    int l=0, r=0;
    ll ans=0;
    unordered_map<int, int> mp;
    while(r<n){
        mp[a[r]]++;
        while(mp.size()>k){
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        ans += r-l+1;
        // ans++;
        // cout<<l<<" "<< r << ": " << ans << "\n";
        r++;
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