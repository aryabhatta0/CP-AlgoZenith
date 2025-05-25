#include <bits/stdc++.h>
using namespace std;
#define ll long long

// can only have max (n-1)/2 tails
// dp[i][j]: tossing i...n coins with only j more tails poss
// ans = dp[0][(n-1)/2]

// w/o setprecision, cout prints only 6 digits after decimal.

int n; 
vector<double> p;
vector<vector<double>> dp;

double rec(int lev, int tails){
    // if(tails<0) return 0;
    if(lev==n) return 1;
    if(tails<0) tails = 0;

    if(dp[lev][tails]!=-1) return dp[lev][tails];

    // choices //
    double ans=0.0;
    // head
    ans += p[lev] * rec(lev+1, tails);

    // tail
    if(tails>0) ans += (1-p[lev]) * rec(lev+1, tails-1);

    return dp[lev][tails] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;     // odd
    p.resize(n);
    for(int i=0; i<n; i++) cin>>p[i]; 

    dp.resize(n, vector<double>((n+1)/2, -1));
    cout << setprecision(15) << rec(0, (n-1)/2) << "\n";

    // print dp
    // cout << "dp: \n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<(n+1)/2; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // } cout << "\n";

    return 0;
}