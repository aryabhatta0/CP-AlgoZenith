// TLE

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// check if there exists a subarr of len mid starting at lo which contains all the element
bool check(int len, int start, int a[], int n, int distinct){
    unordered_set<int> st;
    for(int i=start; i<start+len && i<n; i++){
        st.insert(a[i]);
    }

    return st.size()==distinct;
}

void solve(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    int distinct=st.size();
    
    // bS on every start
    int ans=n;
    for(int i=0; i<n; i++){
        int lo=0;   // subarr len starting at i
        int hi=ans;    //n-i?
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid, i, a, n, distinct)){
                ans=min(ans, mid);
                // cout << "subarr of len= " << mid << " possible at: " << i << "\n";
                hi=mid-1;
            } else
                lo=mid+1;
        }
    }
    cout << ans << "\n";
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t; cin>>_t;
    while(_t--){
        solve();
    }
    return 0;
}