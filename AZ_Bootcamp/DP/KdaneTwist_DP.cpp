// Check another one for Q details
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// each small array has these properties
struct Info {
    ll leftSum=0;
    ll rightSum=0;
    ll maxSum=0;
    ll totSum=0;

    Info() : leftSum(0), rightSum(0), maxSum(0), totSum(0) {}
};

// use ending at i dp
ll dp(vector<int>& order, vector<Info>& arrays){
    ll prev = arrays[order[0]].rightSum;    // prev stores max sum ending at last of prev array
    ll ans = arrays[order[0]].maxSum;
    for(int i=1; i<order.size(); i++){
        int ind = order[i];

        // 1. Last ans
        // 2. curr maxSum
        // 3. prev + leftSum
        ans = max({ans, prev + arrays[ind].leftSum, arrays[ind].maxSum});
        prev = max(arrays[ind].rightSum, prev + arrays[ind].totSum);
        // ans = max({ans, prev});
    }
    return ans;
}

void solve(){
    int n, m; cin>>n>>m;

    // n small arrays
    vector<Info> arrays(n);

    for (int i = 0; i < n; i++) {
        int sz; cin >> sz;
        vector<int> arr(sz);
        for (int j=0; j<sz; j++) cin >> arr[j];

        Info curr;

        /** Ensure you must choose at least one element for the sum, i. e. it cannot be empty. */
        // left sum
        ll currSum = arr[0];
        curr.leftSum = arr[0];
        for (int j=1; j<sz; j++) {
            currSum += arr[j];
            curr.leftSum = max(curr.leftSum, currSum);
        }

        // total sum
        curr.totSum = accumulate(arr.begin(), arr.end(), 0LL);

        // right sum
        currSum = arr[sz - 1];
        curr.rightSum = arr[sz - 1];
        for (int j = sz - 2; j >= 0; j--) {
            currSum += arr[j];
            curr.rightSum = max(curr.rightSum, currSum);
        }

        // max sum (Kadane’s algorithm)
        ll prev = arr[0];
        curr.maxSum = arr[0];
        for (int j = 1; j < sz; j++) {
            prev = max(1LL*arr[j], prev + arr[j]);
            curr.maxSum = max(curr.maxSum, prev);
        }

        arrays[i] = curr;
    }

    vector<int> order(m);
    for(int i=0; i<m; i++) {
        int x; cin>>x;
        order[i] = --x;     // 0-based indexing
    }

    cout << dp(order, arrays) << "\n";
}


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}