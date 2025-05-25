#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001];
// dp[i][j] = lcs of i..n1 & j...n2
// ans = dp[0][0]

/** we need to find substring, not subseq! */
// dp[i][j] = longest substring starting at i & j of s1 & s2 resp.
// ans = max of dp

int rec(int i, int j){
    if(i>=s1.size() || j>=s2.size()) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=0;
    if(s1[i]==s2[j]) ans=1+rec(i+1, j+1);
    // else {
    //     ans = max(rec(i+1, j), rec(i, j+1));
    // }
    
    return dp[i][j] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>s1>>s2;
        memset(dp, -1, sizeof(dp));
        // cout << rec(0, 0) << "\n";

        int ans = 0;
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                ans = max(ans, rec(i, j));
            }
        }
        cout << ans << "\n";

        // print dp
        // cout << "dp: \n";
        // for(int i=0; i<=s1.size(); i++){
        //     for(int j=0; j<=s2.size(); j++) cout << dp[i][j] << " ";
        //     cout << "\n";
        // } cout << "\n";
    }
    return 0;
}