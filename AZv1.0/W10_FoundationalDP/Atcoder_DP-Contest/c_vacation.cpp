#include <bits/stdc++.h>
using namespace std;
#define ll long long

// choices -> recursion
// dp[i] -> what else matters for this? if we are doing same activity as last day.

// dp[i][3]: max happiness during i...n days given last activity
// ans = dp(0, -1)

int n; 
vector<vector<int>> happy;
ll dp[100100][3];

ll rec(int lev, int prev){
    if(lev==n) return 0;
    if(prev!=-1 && dp[lev][prev]!=-1) return dp[lev][prev];

    // choices
    ll ans = 0;
    for(int i=0; i<3; i++){
        if(prev==i) continue;
        ans = max(ans, happy[lev][i] + rec(lev+1, i));
    }

    return dp[lev][prev] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    happy.resize(n, vector<int>(3));
    for(int i=0; i<n; i++) cin>>happy[i][0]>>happy[i][1]>>happy[i][2];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, -1) << "\n";
    return 0;
}