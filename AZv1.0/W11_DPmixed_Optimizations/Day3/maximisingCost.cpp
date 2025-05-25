#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
3
akcbd 2
3
a d 55
b z 100
b c 50
srtlmx 2
2
e a -167
c v -932
abcd 2
4
x y 10
y z 100
a x -150
z d -150
*/

string s; int k;
int n;
// map<char, pair<char, int>> mp;

// int dp[101][101];   // dp[i][j] = max value of string s[i..n] with k-j change left

// dp[i][j][k] = max value of str [0..i-1] with j changes left and curr char = k
// We are changing the ith char if (i-1 & i) adds to the cost
// ans = max of dp[n-1][k][ch] for all ch 

// we will change i to get the score from (i-1 & i) only if this score is greater than the one from (i & i+1)
ll dp[101][101];   // curr char toh string se hi pata chal jayega

// int dp[101][101][26];  
map<pair<char, char>, int> mp;

ll rec(int lev, int change){
    if(lev == 0) return 0;

    if(dp[lev][change] != -1) return dp[lev][change];

    // choices for s[lev]
    for(int i=0; i<26; i++){
        // if more profit from (i & i+1) 
        // if((lev+1<n) && (mp[{s[lev], s[lev+1]}] > mp[{s[lev], s[lev-1]}])) continue;
        
        if(i == s[lev]-'a'){
            dp[lev][change] = max(dp[lev][change], rec(lev-1, change) + mp[{s[lev-1], s[lev]}]);
        }
        else{
            if(change > 0){
                ll dec;
                if(lev+1<n) dec = mp[{s[lev], s[lev+1]}];
                else dec = 0;

                char temp = s[lev];
                s[lev] = 'a' + i;

                ll add;
                if(lev+1<n) add = mp[{s[lev], s[lev+1]}];
                else add = 0;

                if(mp[{s[lev-1], s[lev]}] >= dec)
                    dp[lev][change] = max(dp[lev][change], rec(lev-1, change-1) + mp[{s[lev-1], s[lev]}] - dec + add);
                s[lev] = temp;
            }
        }
    }

    return dp[lev][change];
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>s>>k;
        n = s.size();
        int m; cin>>m;
        mp.clear();
        while(m--){
            char x, y; int c;
            cin>>x>>y>>c;
            mp[{x, y}] = c;
        }

        memset(dp, -1, sizeof(dp));
        cout << rec(n-1, k) << "\n";
    }
}