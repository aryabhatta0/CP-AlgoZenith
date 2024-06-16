// Meet in the middle
// https://maang.in/problems/Target-Subsets-141?resourceUrl=cs99-cp512-pl3527-rs141

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Meet in the middle:
 * If the problem involves generating subsets, and 2^N isn't possible
 * Look at the constraints and check if 2^(N/2) is possible     : N<=40

 * Divide the problem into 2 subproblems (subarrays)  
 * Generate all of its subset solns (sum here)
 * and check if u combine them, to do what's asked for
 */

// Time: n/2 * 2^(n/2)

vector<int> getSubsetSum(vector<int> a, int start, int end){
    int len= end-start+1;
    // each mask represent a subset
    // there'll be max 2^len subsets
    // with the mask for all elems selected being 2^n-1
    vector<int> subsetSum;
    for(int mask=0; mask<pow(2, len); mask++){
        int sum=0;
        for(int i=0; i<len; i++){
            if(mask & (1<<i)) sum+=a[start+i];
        }
        subsetSum.push_back(sum);
    }
    return subsetSum;
}

void solve(){
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    /** u can split based on parity of ind as well like chossing alternate elements*/
    vector<int> b = getSubsetSum(a, 0, n/2);
    vector<int> c = getSubsetSum(a, n/2+1, n-1);

    // cout << "B: "; for(auto it: b) cout << it << " "; cout << "\n";
    // cout << "C: ";for(auto it: c) cout << it << " "; cout << "\n";

    ll ans=0;
    sort(c.begin(), c.end());
    for(int i=0; i<b.size(); i++){
        int req = x - b[i];
        ll cnt = upper_bound(c.begin(), c.end(), req) - c.begin();
        ans += cnt;
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