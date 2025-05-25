#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
 * dp[i][j]: len of LCS of s[0...i] & t[0...j]
 * return dp[m][n]
 * We find the lcs string after finding dp - backtracking
 * Logic: Move in the dirn of higher lcs, if equal, then add that char to lcs
*/

string s, t;
int dp[3003][3003];

int rec(int i, int j){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    if(s[i]==t[j]) ans = 1 + rec(i-1, j-1);
    else ans = max(rec(i-1, j), rec(i, j-1));

    return dp[i][j] = ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>t;

    memset(dp, -1, sizeof(dp));
    int n=s.size(), m=t.size();
    rec(n-1, m-1);
    // cout << "lcs= " << dp[n-1][m-1] << "\n";

    // print dp
    // cout << "dp: \n";
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // } cout << "\n";

    string ret = "";

    n--; m--;
    while(n>=0 && m>=0) {
        if(s[n] == t[m]) {
            ret += s[n];
            n--; m--;
        }
        else if(n==0 && m==0) break;
        else if(n==0) m--;
        else if(m==0) n--;
        else if(dp[n - 1][m] > dp[n][m - 1]) n--;
        else m--;
    }

    reverse(ret.begin(), ret.end());
    cout << ret << endl;

    // This editorial code doen't work cause they had the dp table from 1.. with 0th ind as dummy.
    /*
    while(n && m) {
		if(s[n - 1] == t[m - 1]) {
			ret += s[n - 1];
			n--;
			m--;
		}
		else if(dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
    }
    reverse(ret.begin(), ret.end());
    */

    return 0;
}