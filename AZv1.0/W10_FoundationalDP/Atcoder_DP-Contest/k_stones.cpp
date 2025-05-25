#include <bits/stdc++.h>
using namespace std;
#define ll long long


// dp[i]: find if having i stones is a winning state or losing
// winning state means whoeve plays first wins and vice-versa

int n, k; 
vector<int> a;
int minMove;
// int dp[100100];
vector<int> dp;

// returns if lev is a winning state
int rec(int lev){
    // if(lev==0) return 0;
    if(lev < minMove) return 0;
    // if(lev<=0) return 0;  
    if(dp[lev]!=-1) return dp[lev];

    cout << "uhh lev=" << lev << "\n";
    // if all possible next state leads to a winning state, then this is a losing state
    // if any of next state is a losing state, then this is a winning state
    int res=0;
    for(auto it: a){
        if(rec(lev-it)==0) {    // if any losing next state
            res = 1;
            break;
        }
    }

    // cout << "returning for lev=" << lev << "\n";
    return dp[lev]=res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];
    minMove = *min_element(a.begin(), a.end());

    // memset(dp, -1, sizeof(dp));
    dp.resize(k+1, -1);
    if(rec(k)==1) cout << "First\n";
    else cout << "Second\n";
    return 0;
}