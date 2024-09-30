// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Nearest Smaller Way
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        // nearest smaller bar index to the left
        vector<int> left(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            left[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }

        // nearest smaller bar index to the right
        vector<int> right(n);
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            right[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        // cout<<"Left: "; for(int i=0; i<n; i++) cout<<left[i]<<" "; cout<<"\n";
        // cout<<"Right: "; for(int i=0; i<n; i++) cout<<right[i]<<" "; cout<<"\n";
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, (right[i]-left[i]-1) * heights[i]);
        }
        return ans;
    }

    // Just one stack
    // Storing indices, and calci area whenever a smaller value come in the way
    // Dry run with a example to get the idea
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                // calculate area for rect with height at top
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // Example input
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}