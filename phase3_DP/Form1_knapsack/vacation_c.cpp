// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// choices => recursion
// dp[lev] -> what else matters for this? Can't do same activity again. Track last activity.

// dp[lev][last] = max happiness in lev...n-1 given 'last' act
// ans = rec(0, -1)

int n;
vector<vector<int>> happy;
int dp[100100][3];

int rec(int lev, int last){
    if(lev==n) return 0;
    if(last!=-1 && dp[lev][last]!=-1) return dp[lev][last];

    // choices
    int ans=0;
    for(int i=0; i<3; i++){
        if(i==last) continue;
        ans = max(ans, rec(lev+1, i) + happy[lev][i]);
    }
    return dp[lev][last] = ans;
}

void solve(){
    cin>>n;
    happy.resize(n, vector<int>(3));
    for(int i=0; i<n; i++)
        cin>>happy[i][0]>>happy[i][1]>>happy[i][2];
    
    memset(dp, -1, sizeof(dp));
    cout << rec(0, -1) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}