// https://maang.in/problems/Height-of-Soldiers-88?resourceUrl=cs117-cp540-pl3642-rs88&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: There are N soldiers standing in a row, numbered 1 through N. The height of i-th soldier is Hi. 
// For each non-empty contiguous segment of the line, strength is defined as the minimum height of the soldier in that segment.
// Find the maximum strength for each x size group, for all groups of size x between 1 to N.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++) cin>>height[i];

    // nearest smaller element to the left and right
    vector<int> left(n), right(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && height[st.top()] >= height[i]) st.pop();
        left[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }

    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && height[st.top()] >= height[i]) st.pop();
        right[i] = (st.empty() ? n : st.top());
        st.push(i);
    }

    vector<int> ans(n+1);
    for(int i=0; i<n; i++){
        int x = right[i]-left[i]-1;
        // height[i] could be the min element for groups of size 1,2,...x
        // but since ans1 >= ans2 >= ... >= ansN , we're smartly updating it just for size x
        ans[x] = max(ans[x], height[i]);
    }

    // update for rest of sizes?
    for(int i=n-1; i>=1; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }

    // print ans
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}