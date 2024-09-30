// https://maang.in/problems/Edit-Distance-1262?resourceUrl=cs100-cp506-pl3407-rs1262
// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int dp[510][510];
// dp[i][j] = min operations to convert [0....i] & [0....j]

// This was so cool. Make notes of this.
/* Concept:
 * Multi-sequence: Form3 -> [0...i] & [0...j]
 * Try out all cases for transition, take optimal.
 * Use pen and paper to dry run.
*/

string s1, s2; 
int n, m;

int rec(int i, int j){
    // base case
    if(i<0 || j<0) return max(i+1, j+1);

    // cache check
    if(dp[i][j]!=-1) return dp[i][j];

    // transition
    // 3options: insert, remove, and replace
    int ans=1e9;
    if(s1[i]==s2[j]) ans = rec(i-1, j-1);   // match remaining
    else {      // insert, remove, replace
        ans = 1 + min({rec(i, j-1), rec(i-1, j), rec(i-1, j-1)});
    }

    // save and return
    return dp[i][j] = ans;
}

void solve() {
    cin>>s1>>s2;
    n=s1.length(); m=s2.length();

    memset(dp, -1, sizeof(dp));
    cout << rec(n-1, m-1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}