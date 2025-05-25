#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// dp[i][last] = number of i sized string with last 3 bits as last
// = ways to fill 0...i
ll dp[1010101][8];
void precompute() {
    memset(dp, 0, sizeof(dp));
    for(int k=0; k<8; k++) dp[3][k] = 1;

    for(int i=4; i<1e6+1; i++) {    // lev
        for(int j=0; j<2; j++) {    // 0/1 at lev

            for(int k=0; k<8; k++) {
                if(k==2 && j==0) continue;      // no "0100"
                int last = k;
                last &= (~(1<<2));  // unset last bit
                last <<= 1;
                last |= j;  // change first bit

                (dp[i][last] += dp[i-1][k]) %= mod;
            }
        }
    }
}

void solve(){
    int n; cin>>n;
    if(n<=3) {
        cout << pow(2, n) << "\n";
        return;
    }

    ll ans=0;
    for(int last=0; last<8; last++) {
        (ans += dp[n][last]) %= mod;
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precompute();
    int t; cin>>t; while(t--)
    solve();
    return 0;
}