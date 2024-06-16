// https://www.spoj.com/problems/ACODE/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// dp[lev] = no. of ways of encoding lev...n-1
// ans = dp[0]

/*
Take care of base cases. Dry run to check.
Look at iterative way
*/

ll dp[5005];
string n;

// Iterative dp
int countDecodings(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    
    vector<ll> dp(n + 1, 0);
    dp[n] = 1;  // Base case: there's one way to decode an empty string
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            dp[i] = 0;  // No way to decode a string that starts with '0'
        } else {
            dp[i] = dp[i + 1];  // At least the single character can be decoded
            if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                dp[i] += dp[i + 2];  // Two characters can be decoded together
            }
        }
    }
    
    return dp[0];
}

// Recursive dp
ll rec(int lev){
    if(lev == n.size()) return 1;  // If we reach the end, it's a valid decoding
    if(n[lev] == '0') return 0;    // Strings starting with '0' are invalid
    if(dp[lev] != -1) return dp[lev];

    // choices
    ll ans = rec(lev + 1);  // Decode single character
    
    // Decode two characters if valid
    if(lev + 1 < n.size()) {
        int dig = (n[lev] - '0') * 10 + (n[lev + 1] - '0');
        if(dig >= 10 && dig <= 26) {
            ans += rec(lev + 2);
        }
    }

    return dp[lev] = ans;
}

void solve(){
    while(1){
        cin>>n;
        if(n=="0") return;

        memset(dp, -1, sizeof(dp));
        cout << rec(0) << "\n";

        // cout << "printing dp states for n=" << n << ": \n";
        // for(int i=0; i<5000; i++){
        //     if(dp[i]==-1) break;
        //     cout << "dp[" << i << "]=" << dp[i] << "\t";
        // } cout << "\n";
    }
}

int32_t main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}