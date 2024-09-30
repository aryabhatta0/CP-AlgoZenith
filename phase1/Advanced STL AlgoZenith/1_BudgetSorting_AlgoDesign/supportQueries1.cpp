// Algorithmic Design: struct
// https://maang.in/problems/Support-Queries-I-83?resourceUrl=cs99-cp510-pl3443-rs83
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct mydata {
    multiset<int> mst;
    ll sum=0;

    void add(int x) {
        mst.insert(x);
        sum+=x;
    }
    void remove(int x) {
        auto it = mst.find(x);
        if(it!=mst.end()){
            sum -= (*it);
            mst.erase(it);
        }
    }
    void getMin() {
        if(!mst.empty()) cout << *(mst.begin()) << "\n";
        else cout << "-1\n";
    }
    void getMax() {
        if(!mst.empty()) cout << *(mst.rbegin()) << "\n";
        else cout << "-1\n";
    }
    void getSum() {
        cout << sum << "\n";
    }
};


void solve(){
    int q; cin>>q;

    mydata data;
    while(q--){
        int act; string str;
        cin>>act>>str;
        int x;

        switch(act) {
            case 1: 
                data.add(stoi(str));
                break;
            case 2:
                data.remove(stoi(str));
                break;
            case 3:
                data.getMin();
                break;
            case 4:
                data.getMax();
                break;
            case 5:
                data.getSum();
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}