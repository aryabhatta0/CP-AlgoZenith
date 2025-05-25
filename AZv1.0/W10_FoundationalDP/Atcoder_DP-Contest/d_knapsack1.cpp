#include <bits/stdc++.h>
using namespace std;
#define ll long long

// max sum can be W cap
// maximize value

/**
 * choices -> pick/skip -> recursion
 * dp[i][cap]: i...n bag left, cap restriction
 * return dp[0][cap]
*/


ll dp[110][100100];
int n, cap;
vector<int> w, v;

ll rec(int lev, int cap){
    if(cap<=0) return 0;
    if(lev>=n) return 0;
    if(dp[lev][cap]!=-1) return dp[lev][cap];

    // pick
    ll val1 = 0;
    if(cap>=w[lev]){
        val1 += v[lev];
        val1 += rec(lev+1, cap-w[lev]);
    }

    // skip
    ll val2 = rec(lev+1, cap);

    return dp[lev][cap] = max(val1, val2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>cap;
    w.resize(n), v.resize(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, cap) << "\n";

    return 0;
}