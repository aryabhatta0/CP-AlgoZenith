// https://maang.in/problems/Super-Minimum-Sum-78?resourceUrl=cs117-cp540-pl3642-rs78&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: You have given an array A of size N. A1, A2, ..., An are the elements of the array.
// Find the sum of the minimum of all subarrays possible of array A.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Concept: Individual Elemment Contribution
// - Think of the number of subarrays having arr[i] as minimum
void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    // nearest smaller element to the left and right
    vector<int> left(n), right(n);

    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }

    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = (st.empty() ? n : st.top());
        st.push(i);
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        ans += 1LL * arr[i] * (i-left[i]) * (right[i]-i);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}