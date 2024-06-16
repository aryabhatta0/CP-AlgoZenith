// https://maang.in/problems/Multimap-AZ101-363?resourceUrl=cs99-cp510-pl3439-rs363
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int q; cin>>q;
    multimap<string, int> mp;
    string str;
    while(q--){
        cin>>str;
        if(str=="add") {
            string x; cin>>x;
            int y; cin>>y;
            // mp[x]=y;
            mp.insert({x, y});
        } 
        else if(str=="erase"){
            string x; cin>>x;
            auto it = mp.find(x);
            if(it != mp.end()) mp.erase(it);
        } 
        else if(str=="eraseall"){
            string x; cin>>x;
            if(mp.find(x) != mp.end()) mp.erase(x);
        } 
        else if(str=="print"){
            string x; cin>>x;
            auto it = mp.find(x);
            if(it != mp.end()) cout << it->second << "\n";
            else cout << "0\n";
        }
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