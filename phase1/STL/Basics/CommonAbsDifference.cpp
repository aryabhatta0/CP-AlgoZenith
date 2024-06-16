// Common Absolute Difference
// https://maang.in/problems/Common-Absolute-Difference-379?resourceUrl=cs99-cp510-pl3438-rs379
// You are given an array A of N integers and an integer K. Find the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K
// Notice K≠0, can you handle the case when K=0?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// SOLUTION (Easier way)
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }
   		long long ans = 0;
        for (int i = 0; i < n; ++i) {
            m[a[i]]--;
            ans += m[a[i]-k];
            ans += m[a[i]+k];
        }
        cout << ans << "\n";
    }
    return 0;
}

// (MINE)
void solve(){
    int n, k; cin>>n>>k;
    int a[n];
    unordered_map<ll, vector<int>> mp;    // val, pos
    for(int i=0; i<n; i++) {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }

    ll cnt=0;
    for(int i=0; i<n; i++) {
        ll x = a[i]+k;
        if(!mp[x].empty()){
            // look for no. of elem (posn) > i
            cnt += mp[x].end() - upper_bound(mp[x].begin(), mp[x].end(), i);
        }

        x= a[i]-k;
        if(!mp[x].empty()){
            // look for no. of elem (posn) > i
            cnt += mp[x].end() - upper_bound(mp[x].begin(), mp[x].end(), i);
        }
    }

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}