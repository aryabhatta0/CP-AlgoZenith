// TLE
// DP approach
// but won't do caching across queries since we doing i...n-1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n;

// dp[1001001][2][2][2];
// dp[lev][prev3][prev2][prev1] = number of ways to fill lev...n-1 so that 0100 is not a substring given previous 3 choices
// ans = dp[0][1][1][1]         // coz 111 won't disturb init
// dp[lev][prev3][prev2][prev1] = dp[lev+1][prev2][prev1][0] + dp[lev+1][prev2][prev1][1]

int dp[1001001][2][2][2];

// ik what i want to do, but there is sth missing
ll rec(int lev, int prev3, int prev2, int prev1){
    if(lev==n) return 1;

    if(dp[lev][prev3][prev2][prev1]!=-1) return dp[lev][prev3][prev2][prev1];

    // choices : 0/1
    ll ans1=0, ans2=0;

    // 0 can't be added here
    if(lev!=0 && lev!=1 && lev!=2 && prev3==0 && prev2==1 && prev1==0) ans1=0;
    else ans1 = rec(lev+1, prev2, prev1, 0);

    // 1 can always be added
    ans2 = rec(lev+1, prev2, prev1, 1);

    return dp[lev][prev3][prev2][prev1] = (ans1+ans2)%mod;  // + ?
}


int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>n;
        cout << rec(0,0,0,0) << "\n";
        
    }
    return 0;
}