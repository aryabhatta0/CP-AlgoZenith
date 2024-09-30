// https://maang.in/problems/Towers-AZ101-362?resourceUrl=cs99-cp510-pl3441-rs362
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** 
auto it = mst.upper_bound(x); 
auto it = upper_bound(mst.begin(), mst.end(), x);

the upper method is slight better in terms of time complexity
*/

void solve(){
    int n; cin>>n;
    // store all the top
    // set to make it sorted
    // to use _bound later

    // 5 3 3 4 3 2
    // 5 3 4

    // we are storing the tops of each blocks
    // multiset<int> mst;
    vector<int> vec;    // we'll maintain it to be sorted
    int x;
    while(n--){
        cin>>x;
        if(vec.empty()) {
            // mst.insert(x);
            vec.push_back(x);
            continue;
        }

        // first elem > x
        auto it = upper_bound(vec.begin(), vec.end(), x);
        if(it!=vec.end()) {
            // mst.erase(it);
            int ind = it - vec.begin();
            vec[ind] = x;
        } else vec.push_back(x);
        // mst.insert(x);
    }
    cout << vec.size() << "\n";
}

void solve2(){
    int n; cin>>n;
    multiset<int> mst;
    int x;
    while(n--){
        cin>>x;
        if(mst.empty()) {
            mst.insert(x);
            continue;
        }
        // first elem > x
        // auto it = upper_bound(mst.begin(), mst.end(), x);
        auto it = mst.upper_bound(x);
        if(it!=mst.end()) mst.erase(it);
        mst.insert(x);
    }
    cout << mst.size() << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}