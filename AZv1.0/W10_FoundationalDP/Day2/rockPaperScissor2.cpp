#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
string moves="";
int ans=0;
string ansMoves="";
map<char, int> mp = {{'P', 0}, {'R', 1}, {'S', 2}};

// dp[i][j][k] = max number of wins if we choose kth choice at ith level with j changes left
int dp[1001][1001][3];
char prev = ' ';

// true if ch2 beats ch1
bool play(char ch1, char ch2){
    if(ch1=='P' && ch2=='S') return true;
    if(ch1=='S' && ch2=='R') return true;
    if(ch1=='R' && ch2=='P') return true;
    return false;
}

int rec(int level, int change, int choice){
    if(change<0) return 0;
    if(level==n) return 0;
    if(dp[level][change][choice] != -1) return dp[level][change][choice];

    // moves += s[level];
    int win = play(s[level], mp[choice]) ? 1 : 0;

    int ans=0;
    for(int i=0; i<3; i++){   // choices for next level
        if(i==choice) {
            ans = max(ans, win+rec(level+1, change, i));
        }
        else {
            ans = max(ans, rec(level+1, change-1, i));
        }
    }

    return dp[level][change][choice] = ans;
}

void solve(){
    ans = 0;
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<3; i++){
        int temp = rec(0, k, i);
        if(temp>ans){
            ans = temp;
            // prev = i;
        }
    }

    cout << ans << "\n";
    // cout << ansMoves << "\n";
    // cout << moves << "\n";
    // cout << prev << "\n";
    // for(int i=0; i<n; i++){
    //     if(play(s[i], prev)){
    //         cout << 'S';
    //     }
    //     else{
    //         cout << prev;
    //     }
    // }
    // cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        solve();
    }
    return 0;
}