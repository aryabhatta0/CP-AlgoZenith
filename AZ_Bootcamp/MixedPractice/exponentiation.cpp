#include <bits/stdc++.h>
using namespace std;
#define int long long

// Modular Exponentiation
// int binpow(int a, int n, int p){
//     if(n==0) return 1;
//     ll temp = binpow(a, n/2, p);
//     temp = (temp * temp) % p;
//     if(n % 2 != 0) temp = (temp * a) % p; // Fix here
//     return temp;
// }

int binpow(int a, int n, int mod){
    int res=1;
    while(n>0){     // we iterate over the bits
        if(n%2) res = (res*a) % mod;    // mult to ans

        // a^2
        a = (a*a) % mod;
        n>>1;   // n /= 2;
    }
    return res;
}

void solve(){
    int a, b, c, p;
    cin >> a >> b >> c >> p;

    if (b == 0 && c != 0) cout << "1\n";
    else if (a % p == 0 || a == 0) cout << "0\n";
    else {
        // Compute B^C % (P-1) first
        int exp = binpow(b, c, p-1);  // Using Fermat's Little Theorem

        // Now compute A^exp % P
        int ans = binpow(a, exp, p);
        cout << ans << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}