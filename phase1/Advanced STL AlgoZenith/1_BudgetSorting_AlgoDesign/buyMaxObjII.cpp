#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Key Ideas:
1. Go Greedy
2. Use of lower and upper bound

- Smallest element >= x        : lower_bound
- Smallest element > x         : uooer_bound
- Num elements <= x            : upper_bound - arr.begin()
- Num elements < x             : lower_bound - arr.begin()
*/

void solve(){
    int n, q; cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    // prefix sum
    for(int i=1; i<n; i++) arr[i] += arr[i-1];

    while(q--){
        int m; cin>>m;

        int ans = upper_bound(arr.begin(), arr.end(), m) - arr.begin();     // no. elements <= m 
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}