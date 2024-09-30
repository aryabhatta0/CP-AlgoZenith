#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

// endingAti : LIS ending at i
// dp[i] = max(dp[i], dp[j]+1) A arr[j]<arr[i]

class Solution {
public:
    int dp[2505];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Never use memset to initialize with 1
        // memset(dp, -1, sizeof(dp));  
        for(int i=0; i<n; i++) dp[i]=1;

        dp[0]=1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            // if(dp[i]==-1) dp[i]=1;
        }

        cout << "dp arr: ";
        for(int i=0; i<n; i++) cout << dp[i] << " ";
        cout << "\n";

        int ans=0;
        for(int i=0; i<n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};