// https://maang.in/problems/Number-of-Subarray-with-sum-at-most-K-59?resourceUrl=cs99-cp512-pl3467-rs59
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int head=-1, tail=0;
    int currSum=0;
    ll ans=0;
    while(tail < n) {
        // cout << "For tail=" << tail;
        while(head+1<n && currSum+a[head+1]<=k){
            currSum += a[head+1];
            head++;
        }
        // cout << " , head extends to " << head << " , adding " << (head-tail+1) << " to ans\n";

        ans += (head-tail+1);

        if(head>=tail) {
            currSum -= a[tail];
            tail++;
        } else {    // jab head -1 se badha hi nahi - empty subarray.
            tail++;
            head = tail-1;
        }        
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}