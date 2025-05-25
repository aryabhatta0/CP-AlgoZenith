// https://maang.in/problems/Nearest-Smaller-Values-AZ101-378?resourceUrl=cs117-cp540-pl3641-rs378&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q. You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // small value aane par, piche ka bada store rakhne ka point nahi hai
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        if(st.empty()) cout << "0 ";
        else cout << st.top()+1 << " ";    // 1-based indexing

        st.push(i);
    }
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}