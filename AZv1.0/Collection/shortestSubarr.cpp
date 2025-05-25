// Prb: https://www.learning.algozenith.com/problems/Shortest-Subarray-55

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**LOGIC:
 * Find no. of distinct elements, say d
 * Use 2ptrs to find subarrays with d distinct elements
 * continue updating ans as min length of all subarrays
*/

/** Official Hint:
 * First, find the number of distinct elements in the entire subarray 
 * and then find the shortest subarray with that number of distinct elements.
*/

// Attempt 1: Tried bS on each start, but TLE
// Attempt 2: Tried to use bS on ans..
// got this idea while creating check() 

void solve(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    int distinct=st.size();

    int tail=0, head=-1;
    int ans=n;
    unordered_map<int, int> mp;
    while(tail<n){
        while(head+1<n && mp.size()<distinct){
            head++;
            mp[a[head]]++;
        }

        if(mp.size()==distinct){
            ans=min(ans, head-tail+1);
            mp[a[tail]]--;
            if(mp[a[tail]]==0) mp.erase(a[tail]);
            tail++;
        } else break;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t; cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}