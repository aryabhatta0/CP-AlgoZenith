// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // an index can store rainwater if there are taller elevations on its left and right side
        vector<int> leftMax(n), rightMax(n);

        leftMax[0]=height[0];
        for(int i=1; i<n; i++) leftMax[i] = max(leftMax[i-1], height[i]);
        rightMax[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1], height[i]);

        int ans=0;
        for(int i=0; i<n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    // two-pointer approach (just keeping it here)
    int trap2(vector<int>& height) {
        int n=height.size();

        int left=0, right=n-1;
        int leftMax=height[0], rightMax=height[n-1];
        int water=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftMax > height[left]) water+= (leftMax-height[left]);
                else leftMax = height[left];
                left++;
            } else {
                if(rightMax > height[right]) water+= rightMax-height[right];
                else rightMax = height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;
    vector<int> A = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Water trapped: " << sol.trap(A) << endl;
    return 0;
}