#include <bits/stdc++.h>
using namespace std;

// Each time you can either climb 1 or M steps. What is the minimum number of climbs you need to do to reach the top, i.e., Nth stair?

void solve(){
    int n, m; cin>>n>>m;

    int ans = n/m;
    ans += (n%m);
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}