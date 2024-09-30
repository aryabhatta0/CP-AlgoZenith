# Approach

`rec(i...j)` represents the maximum coins you can collect by bursting balloons between indices `i` and `j`.

Ways to think:
1.  **"which ballon you'll burst at last"**
2.  building ballons - **"which ballon you'll build first"**

Recursion Relation: 
```cpp
 dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]) 
```

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

## Divide and Conquer 

Seeing how the problem can be broken into similar subproblems, we try to use Partition DP (also called LR DP with partition).

**First Thought:**

The initial idea was to burst one of the ballon and separate the problem into subproblems, one on the left and another on right.

- Use LR DP (`dp[i][j]` = max coins u could get by bursting i...j ballons)
- Find kth optimal ballon to burst
- Subproblems are `[i, k-1]` and `[k+1, j]`

Upon some pondering, I realized that the problem here is that the **subproblems aren't independent.** It'll also depend upon which subproblem you'll solve first.

## Correct Approach - Reverse thinking !

Find which ballon (say k) you'll burst last in `[i..j]`, the coins you'll get for that burst is `dp[i-1] * dp[k] * dp[j+1]`

Then solve the subproblem `[i, k-1]` and `[k+1, j]`

Notice how the subproblems will be independent now.. since both doesn't depend upon each other.


# Complexity
- Time complexity: O(n^3)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n^2)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int dp[303][303];
    int n;

    // #1 max coins you could achieve by bursting ballons [i...j]
    // #2 max coins get after building [i...j] ballons with others already built
    int rec(int i, int j, vector<int>& nums){
        // base case
        if(i>j) return 0;

        // cache check
        if(dp[i][j] != -1) return dp[i][j];

        // transition
        int ans=0;
        // find which ballon you'll burst last
        for(int k=i; k<=j; k++){
            ans = max(ans, rec(i, k-1, nums) + ((i-1 >= 0) ? nums[i-1] : 1) * nums[k] * ((j+1 < n) ? nums[j+1] : 1) + rec(k+1, j, nums));
        }

        // save and return
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        n=nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n-1, nums);
    }
};
```