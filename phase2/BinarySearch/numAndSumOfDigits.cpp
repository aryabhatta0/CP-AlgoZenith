// https://maang.in/problems/Number-Sum-of-Digit-26?resourceUrl=cs99-cp512-pl3459-rs26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Realizing the monotonic space was crucial
// that if the prop holds for X, X+1 will satisfy too

ll sumDigits(ll x){
    string str = to_string(x);
    ll sum=0;
    for(auto it: str){
        sum += (it - '0');
    }
    return sum;
}

bool check(ll x, ll s){
    if(x - sumDigits(x) >= s) return 1;
    else return 0;
}

void solve(){
    ll n, s; cin>>n>>s;
    // X - sumDigits(X) >= S

    ll lo=1, hi=n;
    ll ans=-1;  // first x for which the property holds
    while(lo<=hi){
        ll mid = lo + (hi-lo)/2;
        if(check(mid, s)){
            hi=mid-1;
            ans=mid;
        } else {
            lo=mid+1;
        }
    }

    if(ans==-1) cout << "0\n";
    else cout << (n-ans+1) << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}