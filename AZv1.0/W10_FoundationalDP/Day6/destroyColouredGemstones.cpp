#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];

// dp[i][j] = min time to destroy i...j
// ans = dp[0][n-1]
// dp[i][j] = min of all possibilities
// if(a[i]==a[j]) ans1=dp[i+1][j-1]
// ans2 = dp[i][mid] + dp[mid+1][j]     for all mid=i...j-1

int dp[101][101];

// bool isPalindrome(int i, int j){
//     while(i<j){
//         if(a[i]!=a[j]) return false;
//         i++; j--;
//     }
//     return true;
// }

int rec(int i, int j){
    if(i>=n || j>=n) return 0;
    if(i>j) return 0;
    if(i==j) return 1;
    if(i+1==j) return (a[i]==a[j] ? 1 : 2);
    // if(isPalindrome(i, j)) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    if(a[i]==a[j]) ans = rec(i+1, j-1);
    // else ans = 1+min(rec(i+1, j), rec(i, j-1));

    for(int mid=i; mid<j; mid++){
        if(a[i]==a[mid])    // using this condition reduces time significantly!!
            ans = min(ans, rec(i, mid) + rec(mid+1, j));
    }

    return dp[i][j] = ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        memset(dp, -1, sizeof(dp));
        cout << rec(0, n-1) << "\n";
    }
    return 0;
}