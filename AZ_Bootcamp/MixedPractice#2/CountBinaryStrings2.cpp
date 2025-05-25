#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// dp[i][sate] = number of way in 0...i strings with 'state' state (no. of matchings)
// State diagram is the key!
// Sates: 0/1/2/3 matchings.   Action: 0/1  (must store the matched val at each state)
ll dp[1010101][4];
void precompute() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 0;
    dp[0][3] = 0;

    for(int i=1; i<=1e6; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % mod;
        dp[i][3] = dp[i-1][2];
    }
}

void solve(){
    int n; cin>>n;
    
    ll ans=0;
    for(int state=0; state<4; state++) {
        (ans += dp[n-1][state]) %= mod;
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