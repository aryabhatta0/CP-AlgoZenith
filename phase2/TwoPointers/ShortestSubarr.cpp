// https://maang.in/problems/Shortest-Subarray-57?resourceUrl=cs99-cp512-pl3469-rs57
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    unordered_map<int, int> mp;     // freq map
    for(int i=0; i<n; i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    int dist = mp.size();  // distinct elements
    mp.clear();

    int head=-1, tail=0;
    int ans=mod;    // min len subarr
    while(tail < n){
        while(head+1<n && mp.size()<dist){
            mp[a[head+1]]++;
            head++;
        }

        if(mp.size()==dist)     // ans might not be poss for some tails, so need to check this
            ans = min(ans, head-tail+1);
        else break;     // optimization - abhi ni hoga, toh aage bhi nhi hoga

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