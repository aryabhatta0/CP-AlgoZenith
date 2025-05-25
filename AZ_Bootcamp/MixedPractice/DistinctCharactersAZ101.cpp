// https://maang.in/problems/Distinct-Characters-AZ101-384?resourceUrl=cs117-cp540-pl3641-rs384&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q: You are given a string S. You are given Q queries of two types:
// 1. changing the i-th character to c.
// 2. Find the number of distinct characters in the range [L, R] (1-based Indexing)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Intuition: Query on Strings? 
// One way to think is to look at contributions due to each 26 character "a-z"

void solve(){
    string str; cin>>str;
    int n = str.size();

    // store indices at which each char is present
    vector<set<int>> arr(26);
    for(int i=0; i<n; i++){
        arr[str[i]-'a'].insert(i);
    }

    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int i; char c; cin>>i>>c;
            i--;    // 1-based indexing

            // delete str[i]
            arr[str[i]-'a'].erase(i);
            // add to c
            arr[c-'a'].insert(i);
            // update
            str[i]=c;
        } else {
            int l, r; cin>>l>>r;
            l--; r--;   // 1-based index

            ll cnt=0;
            for(int i=0; i<26; i++){
                // add contribution of this char if it has one val in [l,r]
                auto it = arr[i].lower_bound(l);
                if(it!=arr[i].end() && *it <= r) cnt++;
            }
            cout << cnt << "\n";
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}