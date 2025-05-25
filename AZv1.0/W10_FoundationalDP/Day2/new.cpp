#include <bits/stdc++.h>
using namespace std;

int n, k;
string s; 

// dp[i][k]:  max win poss moves for i...n when u have only k change left
// ans = dp[0][k]
// wrong coz we will need prev move also

// dp[i][j][k]:  max win possible in moves from i...n when u have only 
// j change left, and ur last move was k
// ans = dp(0, k, -1)

int dp[1001][1001][3];
map<int, char> mp = {{0, 'P'}, {1, 'R'}, {2, 'S'}};

// returns 1 if ch1 wins over ch2
int play(char ch1, char ch2){
    if(ch1=='P' && ch2=='R') return 1;
    if(ch1=='R' && ch2=='S') return 1;
    if(ch1=='S' && ch2=='P') return 1;
    return 0;
}

int rec(int i, int j, int k){
    if(j<0) return 0;
    if(i==n) return 0;

    if(k!=-1 && dp[i][j][k] != -1) return dp[i][j][k];

    // choices
    // P, R, S
    int ans = 0;
    for(int ch=0; ch<3; ch++){
        int win = play(mp[ch], s[i]);
        if(k==-1 || ch==k) ans = max(ans, win + rec(i+1, j, ch));
        else if(j>0)    // can change
            ans = max(ans, win + rec(i+1, j-1, ch));
    }

    return dp[i][j][k] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;

        memset(dp, -1, sizeof(dp));
        cout << rec(0, k, -1) << "\n";

        // print dp
        for(int i=0; i<n; i++){
            cout << "dp[" << i << "]:\n";
            for(int j=0; j<=k; j++){
                for(int l=0; l<3; l++){
                    cout << dp[i][j][l] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        // also print the lexico smallest string
        // string ans = "";
        // for(int i=0; i<n; i++){
            
    }
    return 0;
}