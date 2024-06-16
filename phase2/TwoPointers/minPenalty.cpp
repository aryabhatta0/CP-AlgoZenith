// Sliding Window-1
// https://maang.in/problems/Minimum-Penalty-64?resourceUrl=cs99-cp512-pl3469-rs64

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, d; cin>>n>>d;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    unordered_map<int, int> mp;     // freq map

    // window
    for(int i=0; i<d; i++) mp[a[i]]++;
    int ans=mp.size();    // min panelty

    // sliding window
    for(int i=d; i<n; i++){     // i - end of window
        mp[a[i]]++;
        mp[a[i-d]]--;
        if(mp[a[i-d]]==0) mp.erase(a[i-d]);
        ans = min(ans, (int)mp.size());
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