// Meet in the Middle - Diving problems into subproblems !

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Meet in the Middle
 * Moving b - the partition is at b
 * Update pair_sum for [b+1, n)
 * Loop over a, check if T-a-b exists in pair_sum
 */

void solve(){
    int n, x; cin>>n>>x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    map<int, bool> mp;  // if a pair sum exists after B
    // fix b
    mp[arr[n-1]+arr[n-2]]=1;
    for(int b=n-3; b>=1; b--){
        // loop over a
        for(int a=0; a<b; a++){
            // check for c+d
            if(mp[x - arr[a] - arr[b]]) {
                cout << "YES\n";
                return;
            }
        }

        // update mp
        // this b could be a c in next iter
        for(int d=b+1; d<n; d++) mp[arr[b]+arr[d]]=1;
    }

    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}