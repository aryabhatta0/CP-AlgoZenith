// WA
// First attempt until I realized direct approach won't work
// since 0100 can be at 2 places, giving same string

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n;

ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res % mod;
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        // cout << pow(2,n) - (n-4+1)*pow(2, n-4) << "\n";
        if(n<=3) cout << pow(2,n) << "\n";
        else {
            // cout << (binpow(2,n) - (((n-4+1)*binpow(2, n-4))%mod) + mod)%mod << "\n";
            ll ans = binpow(2,n);
            ans -= ((n-4+1)*binpow(2, n-4))%mod;
            ans = (ans + mod)%mod;
            cout << ans << "\n";
        }
    }
}