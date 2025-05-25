// https://maang.in/problems/Maximum-Number-of-Customers-AZ101-369?resourceUrl=cs117-cp540-pl3641-rs369&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: You are given the arrival and leaving time of N customers. Find the maximum number of customers at any time. All arriving and leaving times are distinct.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


// Intuition: Maintain count by adding +1 on arrival, and -1 on departure. Return max of cnt.
void solve(){
    int n; cin>>n;
    set<pair<int, int>> st;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        st.insert({a, 1});
        st.insert({b, -1});
    }

    int ans=0;
    int cnt=0;
    for(auto it: st){
        cnt += it.second;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}