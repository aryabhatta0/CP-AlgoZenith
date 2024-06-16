// https://maang.in/problems/Longest-AP-AZ101-340?resourceUrl=cs99-cp510-pl3421-rs340

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int len=0;
    int cd=-1;
    int curr_len=0;
    for(int i=0; i<n-1; i++) {
        if(a[i+1]-a[i]!=cd) {
            cd=a[i+1]-a[i];
            curr_len=2;
        } else curr_len++;
        len = max(len, curr_len);
    }
    cout << len << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}