#include <iostream>
using namespace std;
using lli = long long;

// Find a^b % p
// Time: O(logN)
lli binpow(lli a, lli b, lli mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        lli temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}

// QUESTION: Compute the expression ((a*b - c^d) / e mod p)

int main() {
    // Input values
    lli a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    // Apply modulo to avoid overflow
    lli mod = 1000000007; // or any other modulo value
    a %= mod;
    b %= mod;
    c %= mod;
    e %= mod;

    // Compute intermediate results
    lli x1 = (a * b) % mod;
    lli x2 = binpow(c, d, mod);

    // Calculate expression: (a * b - c^d) % mod
    lli x3 = (x1 - x2 + mod) % mod;

    // Calculate modular inverse of e: e^(mod-2) % mod
    lli x4 = binpow(e, mod - 2, mod);

    // Final result: ((a * b - c^d) / e) % mod
    lli ans = (x3 * x4) % mod;

    // Ensure the result is non-negative
    ans = (ans + mod) % mod;

    // Output the result
    cout << ans << endl;

    return 0;
}
