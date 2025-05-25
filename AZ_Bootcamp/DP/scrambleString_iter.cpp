// https://leetcode.com/problems/scramble-string/
#include <bits/stdc++.h>
using namespace std;

// Iterative implementation of `scrambledString.cpp` _/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;

        // DP table: dp[i][j][len] -> can s1[i:i+len-1] be scrambled into s2[j:j+len-1]
        bool dp[n][n][n + 1];
        memset(dp, 0, sizeof(dp));

        // Base case: single character comparison
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        // Fill the DP table for substring lengths greater than 1
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int k = 1; k < len; k++) {  // partition point
                        // Without swapping
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                        // With swapping
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        // Return the final answer for the entire string
        return dp[0][0][n];
    }
};
