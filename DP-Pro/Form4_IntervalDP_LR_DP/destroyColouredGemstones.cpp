#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
int arr[110];

/** Intuition is to see which palindromes the first element be a part of */

// min secs to destroy [l,r]
int dp[110][110];
int rec(int l, int r){
    // base case
    if(l>r) return 0;
    if(l==r) return 1;

    // cache check
    if(dp[l][r]!=-1) return dp[l][r];

    // transition
    int ans = 1 + rec(l+1, r);  // in case nothing matches with arr[l]

    for(int mid=l+1; mid<=r; mid++){
        if(arr[l]==arr[mid]){
            if(mid==l+1) ans = min(ans, 1 + rec(mid+1, r));
            else ans = min(ans, rec(l+1, mid-1) + rec(mid+1, r));
        }
    }

    // save and return
    return dp[l][r] = ans;
}

void solve() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}