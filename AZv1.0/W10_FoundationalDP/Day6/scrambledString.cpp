#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n;
int dp[41][41][41];

// dp[i][j][k]: whether s2 i...j is a scrambled string of s1 k..._
// 4D dp converted to 3D.. since lengths of s1 & s2 are same.

// ans = dp[0][n-1][0]

// if(s2[i]==s1[k]) return dp[i+1][n-1][k+1]
// if(s2[i]==s1[l]) return dp[i+1][n-1][k]

/** Transition:
 * pick a mid. check if (i...mid && mid+1..j can be scrambled with k..mid && mid+1..l) or (i..mid && mid+1..j can be scrambled with ...l && k...)
 * break s2 in 2 parts, if those parts can be scrambled using start or end of s1, TRUE!
*/

bool rec(int i, int j, int k){
    if(i>j) return false;
    if(i==j) return (s2[i]==s1[k] ? true : false);


    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int l = k + (j-i);

    // bool ans=false;
    for(int len=0; len<j-i; len++){
        if(rec(i, i+len, k) && rec(i+len+1, j, k+len+1)) return dp[i][j][k]=true;
        if(rec(i, i+len, l-len) && rec(i+len+1, j, k)) return dp[i][j][k]=true;
    }
    return dp[i][j][k]=false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>s1>>s2;
        n = s1.size();
        memset(dp, -1, sizeof(dp));
        if(rec(0, n-1, 0)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}