#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Takeaways:
 * Range of 2 would be 2^31 here . since two 2^30 can sum to 2^31.
 * Counting Unique Pairs :
    1. Either divide ans by 2 (since each pair counted twice)
    2. Dec map freq as we iterate (so as to not consider that element for upcoming ones)

 *  if(arr[i]==res) ans--;   Notice this check!
 */

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        freq[arr[i]]++;
    }

    // cnt of pairs with sum as power of 2
    ll ans=0;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=31; j++) {
            // arr[i] + num = 2^j
            ll res = (1<<j) - arr[i];
            if(freq.find(res)!=freq.end()) {
                ans += freq[res];
                if(arr[i]==res) ans--;
            }
        }
        // freq[arr[i]]--;
        // if(freq[i]==0) freq.erase(freq[i]);
    }
    cout << ans/2 << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}