// https://leetcode.com/problems/maximum-subarray/description/
// Find max subarray sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Check LeetCode submissions for the `Divide and Conquer` approach.

class Solution {
public:
    // Kdane's Algo //
    int maxSubArray(vector<int>& nums) {
        // we only needed dp[i-1] at each i, so no need of maintaining whole dp
        int n=nums.size();

        ll ans = nums[0];
        ll prev=nums[0];   // prev is max subarr sum till last index
        for(int i=1; i<n; i++){
            prev = max(1LL*nums[i], prev+nums[i]);
            ans = max(ans, prev);
        }
        return ans;
    }

    int maxSubArray2(vector<int>& nums) {
        // ending at i ?
        int n = nums.size();
        vector<ll> dp(n);   // dp[i] = max subarray sum ending at i

        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max(1LL*nums[i], dp[i-1]+nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};