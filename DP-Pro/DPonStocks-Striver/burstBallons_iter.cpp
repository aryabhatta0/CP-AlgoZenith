#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add 1 padding to both ends of the nums array
        vector<int> paddedNums(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            paddedNums[i + 1] = nums[i];
        }
        
        // DP table where dp[i][j] represents the maximum coins we can get by bursting all balloons in the range (i, j)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // Iterate over the length of the subarray (from 1 to n)
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                
                // Try bursting each balloon between left and right, and take the maximum result
                for (int i = left; i <= right; ++i) {
                    dp[left][right] = max(dp[left][right], 
                        paddedNums[left - 1] * paddedNums[i] * paddedNums[right + 1] + 
                        dp[left][i - 1] + dp[i + 1][right]);
                }
            }
        }
        
        // The answer is the maximum coins we can collect by bursting all balloons in the range (1, n)
        return dp[1][n];
    }
};
