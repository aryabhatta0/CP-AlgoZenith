#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        // cout << "nums: ";
        // for(int i=0; i<n; i++) cout << nums[i] << " ";
        // cout << "\n";

        ll ans=INT_MAX;
        for(int i=0; i<n; i++){
            int l=i+1, r=n-1;

            while(l<r && r>i && l<n){
                ll curr = nums[l]+nums[r]+nums[i];
                // cout << "i=" << i << " l=" << l << " r=" << r << " => " << abs(target-curr) << "\n";
                if(abs(target-curr) < abs(target-ans))
                    ans = curr;

                // ans = min(ans, abs(target-curr));
                if(curr<target) l++;
                else r--;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << "\n";
}