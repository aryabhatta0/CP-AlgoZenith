// Q: Chessboard with each cell having a score. 
// Find max score (div by k) to go from top to bottom starting from any col?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;
// vector<vector<int>> score;       // this caused RE ??
int score[101][101];

// dp[i][j][k]: max score (div by k) to go from i...n-1 when u are at jth col & already have score%k
// ans = max of dp[0][j][0] j=0...m-1
int dp[101][101][12];

ll rec(int lev, int col, int sc){
    if(lev>=n) return 0;
    if(col<0 || col>=m) return -1;

    if(dp[lev][col][sc]!=-1) return dp[lev][col][sc];

    ll curr = score[lev][col];
    // choices
    ll ans1=-1, ans2=-1;
    if(col-1>=0){
        ll next = rec(lev+1, col-1, (sc+curr)%k);
        if(next>=0) ans1 = curr + next;
    }

    if(col+1<m){
        ll next = rec(lev+1, col+1, (sc+curr)%k);
        if(next>=0) ans2 = curr + next;
    }

    ll ans=-1;
    if(ans1>=0 && ((sc+ans1)%k)==0) ans=max(ans, ans1);
    if(ans2>=0 && ((sc+ans2)%k)==0) ans=max(ans, ans2);
    // if(ans1>=0 && ans1%k==0) ans=max(ans, ans1);
    // if(ans2>=0 && ans2%k==0) ans=max(ans, ans2);

    return dp[lev][col][sc] = ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m>>k;
        // score.resize(n, vector<int>(m));

        memset(dp, -1, sizeof(dp));
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         for(int sc=0; sc<=k; sc++){
        //             dp[i][j][sc]=-1;
        //         }
        //     }
        // }

        for(int i=0; i<n; i++){
            string str; cin>>str;

            for(int j=0; j<m; j++) score[i][j]=str[j]-'0';
        }

        ll ans=-1;
        for(int col=0; col<m; col++){
            ans = max(ans, rec(0, col, 0));
        }
        cout << ans << "\n";

    }
}