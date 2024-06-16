#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1e6

ll binpow(ll, ll, ll);

// Factorial precomputation
// Useful in nCr calculation
vector<ll> fact(MAX + 1, 0), inv_fact(MAX + 1, 0);
void factorials() {
    fact[0] = 1;

    for (ll i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX] = binpow(fact[MAX], MOD - 2, MOD);

    for (ll i = MAX - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// nCr calculation using factorials
ll ncr(int n, int k) {
    return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
}

// Computing nCr by multiplication
ll multiplication(int n, int r) {
    ll result = 1;

    for (int i = 0; i < r; i++)
        result = (result * (n - i) / (i + 1)) % MOD;

    return result;
}


ll binpow(ll a, ll b, ll mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        ll temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}