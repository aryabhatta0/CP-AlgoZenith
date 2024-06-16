#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    string s; int r;
    // set, multimap
    // set<pair<int, string>> st;
    vector<pair<int, string>> st;
    while(n--){
        cin>>s>>r;
        // st.insert({r, s});
        st.push_back({r, s});
    }
    sort(st.begin(), st.end());

    for(auto it: st){
        cout << it.second << " " << it.first << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}