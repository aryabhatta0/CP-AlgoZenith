// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// INTUITION: Greedy!
// The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int area=0;

        while(l<r){
            area = max(area, (r-l)*min(height[r], height[l]));

            if(height[l]<=height[r]) l++;
            else r--;
        }
        return area;
    }
};

int main(){
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water stored: " << sol.maxArea(height) << endl;
    return 0;
}