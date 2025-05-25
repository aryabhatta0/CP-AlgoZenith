#include <bits/stdc++.h>
using namespace std;

// Recursive - trying all possible moves
// TLE
// I don't think it can be memoized ?

int n, k;
string s;
string moves="";
int ans=0;
string ansMoves="";
vector<char> choices = {'P', 'R', 'S'};

// true if ch2 beats ch1
bool play(char ch1, char ch2){
    if(ch1=='P' && ch2=='S') return true;
    if(ch1=='S' && ch2=='R') return true;
    if(ch1=='R' && ch2=='P') return true;
    return false;
}

void rec(int level, int change, char prev, int win){
    if(change>k) return;
    if(level==n){
        if(win>ans){
            ans = win;
            ansMoves = moves;
        }
        // ans = max(ans, win);
        return;
    }

    for(auto ch: choices){
        if(level==0) prev = ch;

        bool flag = play(s[level], ch);
        if(flag) win++;

        moves += ch;
        if(ch!=prev) change++;
        char temp = prev; prev = ch;
        rec(level+1, change, prev, win);  // 
        prev = temp;
        if(ch!=prev) change--;
        moves.pop_back();

        if(flag) win--;
    }
}

void solve(){
    ans = 0;

    // dp ?


    rec(0, 0, ' ', 0);
    cout << ans << "\n";
    cout << ansMoves << "\n";
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