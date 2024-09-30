// https://maang.in/problems/Nearest-Smaller-Values-AZ101-378?resourceUrl=cs99-cp510-pl3450-rs378&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
// Q: You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Key Concept: Once we encounter a smaller value, all the higher values would be of no use and we don't need to maintain them anymore !
void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        cout << (st.empty() ? 0 : st.top()+1) << " ";
        st.push(i);
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}