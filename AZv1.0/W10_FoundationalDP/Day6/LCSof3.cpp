#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int dp[101][101][101];

int rec(int i, int j, int k){
    if(i>=s1.size() || j>=s2.size() || k>=s3.size()) return 0;
    
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    int ans=0;
    if(s1[i]==s2[j] && s2[j]==s3[k]) return 1+rec(i+1, j+1, k+1);
    else {
        ans = max({rec(i+1, j, k), rec(i, j+1, k), rec(i, j, k+1)});
    }

    return dp[i][j][k] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>s1>>s2>>s3;
        memset(dp, -1, sizeof(dp));
        cout << rec(0, 0, 0) << "\n";
    }
}