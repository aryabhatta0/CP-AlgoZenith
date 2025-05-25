#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    x %= n;

    vector<int> b(n);
    for(int i=0; i<n; i++) {
        // b[i] = a[(i+x) % n];     // wrong
        b[(i+x)%n] = a[i];

        // Solution
        // b[i] = a[(i - x + n) % n];
    }

    for(int i=0; i<n; i++) cout << b[i] <<" ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}