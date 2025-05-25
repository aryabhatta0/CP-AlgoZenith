#include <bits/stdc++.h>
using namespace std;
#define ll long long

// P1: X, P2:Y
// P1: maximize (X-Y) => remove high value
// P2: minimize (X-Y) => remove high value

/**
 * dp[i][j][p=0/1]    val of X-Y with i...j vals left, and pth turn now
 * ans = dp[0][n-1][0]
 * 
 * NOTE: 3rd dimension ke bina bhi ho jaata. Fark nahi padega. Why?
 * dp[i][j]: optimal score for X-Y given X's chance
*/

int n;
vector<int> a;
ll dp[3003][3003][2];

ll rec(int i, int j, int p){
    if(i>j) return 0;

    if(dp[i][j][p]!=-1) return dp[i][j][p];

    // choices
    // each player maximizes their score - other score
    // i+1
    // ll ans1 = a[i] - rec(i+1, j, 1-p);      // think about why - !! ..coz rec returns X-Y for another player.. so Y-X
    ll ans1 = a[i] - rec(i+1, j, 1-p);
    // j-1
    ll ans2 = a[j] - rec(i, j-1, 1-p);

    return dp[i][j][p] = max(ans1, ans2);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n-1, 0) << "\n";
    return 0;
}