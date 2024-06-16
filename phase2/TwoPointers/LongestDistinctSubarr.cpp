// https://maang.in/problems/Longest-Distinct-Subarray-AZ101-371?resourceUrl=cs99-cp512-pl3469-rs371
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    // 2 ptr _/

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int head=-1, tail=0;
    int ans = 0;    // max len subarr
    unordered_map<int, int> mp;     // freq map
    while(tail < n){
        while(head+1<n && mp[a[head+1]]==0){
            mp[a[head+1]]++;
            head++;
        }

        ans = max(ans, head-tail+1);

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