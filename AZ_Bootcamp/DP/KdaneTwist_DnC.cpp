// https://maang.in/problems/Kadane-Twist-908?resourceUrl=cs117-cp540-pl3649-rs908&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: Given n smaller arrays and the ordery they has to be merged, find max sum subarray of the final array
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Kdane: Max Subarray Sum

// you can't make the array for real
// Idea: Mainrain leftSum, rightSum, maxSum, totSum
// to check how two segment can be merged the best  - recursion?

// each small array has these properties
struct Info {
    ll leftSum=0;
    ll rightSum=0;
    ll maxSum=0;
    ll totSum=0;

    Info() : leftSum(0), rightSum(0), maxSum(0), totSum(0) {}
};

// Merges two segments
Info merge(Info& left, Info& right){
    Info res;
    res.totSum = left.totSum + right.totSum;
    res.leftSum = max(left.leftSum, left.totSum + right.leftSum);
    res.rightSum = max(right.rightSum, right.totSum + left.rightSum);
    res.maxSum = max({left.maxSum, right.maxSum, left.rightSum + right.leftSum});
    return res;
}

// recursively solve for required range 
Info rec(int st, int en, vector<int>& order, vector<Info>& arrays){
    if(st==en) return arrays[order[st]];

    int mid = (st+en)/2;

    Info left = rec(st, mid, order, arrays);
    Info right = rec(mid+1, en, order, arrays);
    return merge(left, right);
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

        // max subarray sum (Kadane’s algorithm)
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

    Info ans = rec(0, m-1, order, arrays);
    cout << ans.maxSum << "\n";
}


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}