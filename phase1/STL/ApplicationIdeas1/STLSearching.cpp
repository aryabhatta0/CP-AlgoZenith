// STL Application Ideas 1
// Use of upper_ and lower_bound 
// https://maang.in/problems/STL-Searching-395?resourceUrl=cs99-cp510-pl3443-rs395

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    int act, x;
    while(q--) {
        cin>>act>>x;

        auto it1 = lower_bound(a.begin(), a.end(), x);
        auto it2 = upper_bound(a.begin(), a.end(), x);
        
        switch(act) {
            case 1:
                if(it1!=a.end()) cout << *it1 << " ";
                else cout << "-1 ";
                break;
            case 2:
                if(it2!=a.end()) cout << *it2 << " ";
                else cout << "-1 ";
                break;
            case 3:
                cout << (it2 - a.begin()) << " ";
                break;
            case 4:
                cout << (it1 - a.begin()) << " ";
                break;
        }
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}