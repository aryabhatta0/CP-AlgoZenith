// https://maang.in/problems/Kth-Sum-Value-102?resourceUrl=cs99-cp512-pl3461-rs102
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// returns if there are atleast k pairs (c's elem) with sum<=mid
// check if there exists atleast k element with val <= x in C
bool check(vector<int> a, vector<int> b, int mid, ll k){
    int n=a.size(), m=b.size();
    // cnt num of elems <= x in C
    ll cnt=0;
    for(int i=0; i<n; i++){
        int x=mid-a[i];
        cnt+=upper_bound(b.begin(), b.end(), x)-b.begin();
        if(cnt>=k) return true;
    }
    // if(cnt>=k) return true;
    return false;
}

void solve(){
    int n, m; ll k; 
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // can x be kth element of c(n*m)
    // monotonicity ?
    // if x is >= kth smallest elem

    // bS on ans
    int lo=a[0]+b[0], hi=a[n-1]+b[m-1];
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        bool flag;
        
        // iterate over shorter array for lesser time complexity
        if(n<m)
            flag=check(a, b, mid, k);
        else
            flag=check(b, a, mid, k);
        
        if(flag){
            ans=mid;
            hi=mid-1;
        } else{
            lo=mid+1;
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