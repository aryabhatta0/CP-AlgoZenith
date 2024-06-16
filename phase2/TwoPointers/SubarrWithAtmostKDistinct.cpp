// https://maang.in/problems/Number-of-Subarray-with-at-most-K-distinct-60?resourceUrl=cs99-cp512-pl3468-rs60
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // distinct elements - freq map!
    unordered_map<int, int> mp;
    int head=-1, tail=0;
    ll ans=0;
    while(tail < n){
        // how do we check if we have already seen the next element
        // M-I
        while(head+1<n && mp.size()<=k) {
            mp[a[head+1]]++;
            head++;
        }
        if(mp.size()>k){    // remove last added
            mp[a[head]]--;
            // if(mp[a[head]]==0) mp.erase(a[head]);
            mp.erase(a[head]);
            head--;
        }

        /** M-II : Deletion of 0 elem is necessary as condition in while creates it. */
        // while(head+1<n && ((mp.size()<k) || (mp[a[head+1]]>0))){
        //     mp[a[head+1]]++;
        //     head++;
        // }
        // if(mp[a[head+1]]==0) mp.erase(a[head+1]);

        // update ans
        ans += (head-tail+1);

        // move tail
        if(head>=tail){
            mp[a[tail]]--;
            if(mp[a[tail]]==0) mp.erase(a[tail]);
            tail++;
        } else {
            tail++;
            head = tail-1;
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