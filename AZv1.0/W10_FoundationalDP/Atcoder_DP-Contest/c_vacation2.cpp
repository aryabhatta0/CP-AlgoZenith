#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1e9

ll dp[101010][3];
int n;
vector<vector<ll>> points;
// dp[i][j]: max point gain in i....N-1 when last activity was j (0/1/2)

ll rec(int lev, int act){   // last_act
    if(lev==n) return 0;

    if(dp[lev][act]!=-1) return dp[lev][act];

    if(act==0) return dp[lev][act] = max(points[lev][1]+rec(lev+1, 1), points[lev][2]+ rec(lev+1, 2));
    if(act==1) return dp[lev][act] = max(points[lev][0]+rec(lev+1, 0), points[lev][2]+ rec(lev+1, 2));
    if(act==2) return dp[lev][act] = max(points[lev][1]+rec(lev+1, 1), points[lev][0]+ rec(lev+1, 0));

    // return max()
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    points.resize(n, vector<ll>(3));
    for(int i=0; i<n; i++){
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    ll ans = max({ rec(0, 0), rec(0, 1), rec(0, 2) });;
    cout << ans << "\n";
    return 0;
}