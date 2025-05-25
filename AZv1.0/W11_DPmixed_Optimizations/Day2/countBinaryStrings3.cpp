// Accepted
// Backward DP approach - 0....lev
// Caching across queries _/
// Other dimensions size has to be 3, since there is one for init state

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n;
// int dp[1001001][2][2][2];
int dp[1001001][3][3][3];

/** Caching across queries */   // Going i...n-1 won't allow caching across queries
// dp[lev][next1][next2][next3] = number of ways to fill 0...lev so that 0100 is not a substring given next 3 choices
// ans = dp[n-1][2][2][2]   // 2 means init state

// we are going backwards. so prev was actually next.
ll rec(int lev, int next1, int next2, int next3){
    if(lev<0) return 1;

    if(dp[lev][next1][next2][next3]!=-1) return dp[lev][next1][next2][next3];

    // choices : 0/1
    ll ans1=0, ans2=0;

    // we are going backwards. can't have 0, if 100 is already next
    // if(lev!=n-1 && lev!=n-2 && lev!=n-3 && next1==1 && next2==0 && next3==0) ans1=0;
    if(next1==1 && next2==0 && next3==0) ans1=0;
    else ans1 = rec(lev-1, 0, next1, next2);

    // 1 can always be added
    ans2 = rec(lev-1, 1, next1, next2);

    return dp[lev][next1][next2][next3] = (ans1+ans2)%mod;  // + ?
}


int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin>>n;
        cout << rec(n-1,2,2,2) << "\n";
        
    }
    return 0;
}