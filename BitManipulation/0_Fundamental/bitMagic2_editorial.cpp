// SOLN

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void binary(ll x) {
    for (int i = 63; i >= 0; i--) {
        if (x & (1LL << i))cout << 1;
        else cout << 0;
    }
    cout << endl;
}
int msb(ll x) {
    if (x == 0)return -1;
    if (x < 0)return 63; // negative numbers case.
    return (int)__lg(x);
}
int rsb(ll x) {
    if (x == 0)return -1;
    return msb(x ^ (x - 1));
}
bool pow2(ll &x) {
    if (x <= 1)return false;
    return (__builtin_popcountll(x) == 1);
}
ll pow2_div(ll x) {
    if (x == 0)return -1;
    return (1LL << __builtin_ctzll(x)); // 2^(trailing zeroes in bits).
}
ll pow2_n(ll x) {
    if (x <= 1)return 2;
    return (1LL << (64 - __builtin_clzll(x - 1))); // 2^(64 - leading zeroes in bits).
}
void solve() {
    ll n;
    cin >> n;
    binary(n);
    assert(n == 0 || msb(n) == 63 - __builtin_clzll(n));
    cout << msb(n) << endl;
    assert(n == 0 || rsb(n) == __builtin_ctzll(n));
    cout << rsb(n) << endl;
    cout << pow2(n) << endl;
    cout << pow2_div(n) << endl;
    cout << pow2_n(n) << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
