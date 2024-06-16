// https://maang.in/problems/NQueens-Revisited-143?resourceUrl=cs99-cp512-pl3524-rs143
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
vector<int> currSol;
ll ans=0;

vector<pair<int, int>> knight_moves = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};


bool check(int row, int col){
    for(int i=0; i<currSol.size(); i++){
        // if col same
        if(col==currSol[i]) return 0;
        // if on diagonal
        if(abs(col-currSol[i])==abs(row-i)) return 0;

        // if attacked by knight
        for(auto it: knight_moves){
            if(i+it.first==row && currSol[i]+it.second==col) return 0;
        }
    }
    return 1;
}

void rec(int level){
    // base case
    if(level==n){
        ans++;
        return;
    }

    // choices
    for(int ch=0; ch<n; ch++){
        if(check(level, ch)){
            currSol.push_back(ch);
            rec(level+1);
            currSol.pop_back();
        }
    }
    return;
}

void solve(){
    cin>>n;

    ans=0;
    rec(0);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}