// https://maang.in/problems/Concatenate-Array-AZ101-373?resourceUrl=cs99-cp510-pl3441-rs373
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    // find no. of distinct elements
    set<int> st;
    int x;
    while(n--){
        cin>>x;
        st.insert(x);
    }

    cout << st.size() << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}