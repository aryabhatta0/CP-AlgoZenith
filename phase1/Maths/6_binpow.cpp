#include <iostream>
using namespace std;
using ll = long long;

// Find a^b % p
// Time: O(logN)
ll binpow2(ll a, ll n, ll mod) {
    if (n == 0)
        return 1;

    if (n % 2) {
        return a * binpow(a, n - 1, mod) % mod;
    } else {
        ll temp = binpow(a, n / 2, mod);
        return temp * temp % mod;
    }
}

// AGAIN!
ll binpow(ll a, ll n, ll mod) {
    if(n==0) return 1;

    ll res = binpow(a, n/2, mod);
    res = (res * res) % mod;
    if(n%2!=0) {    // jab odd ho toh ek baar aur multiply kar do
        res = (res * a) % mod;
    }
    return res;
}

ll binpow_iter(ll a, ll n, ll mod) {
    if(n==0) return 1;

    ll res = 1;
    while(n>0){
        // jab odd hai, tabhi multiply karna hai
        if(n%2!=0)
            res = (res * a) % mod;

        a = (a * a) % mod;
        n = n >> 1;  // Same as n = n / 2
    }
    return res;
}




// QUESTION: Compute the expression ((a*b - c^d) / e mod p)

int main() {
    // Input values
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    // Apply modulo to avoid overflow
    ll mod = 1000000007; // or any other modulo value
    a %= mod;
    b %= mod;
    c %= mod;
    e %= mod;

    // Compute intermediate results
    ll x1 = (a * b) % mod;
    ll x2 = binpow(c, d, mod);

    // Calculate expression: (a * b - c^d) % mod
    ll x3 = (x1 - x2 + mod) % mod;

    // Calculate modular inverse of e: e^(mod-2) % mod
    ll x4 = binpow(e, mod - 2, mod);

    // Final result: ((a * b - c^d) / e) % mod
    ll ans = (x3 * x4) % mod;

    // Ensure the result is non-negative
    ans = (ans + mod) % mod;

    // Output the result
    cout << ans << endl;

    return 0;
}
