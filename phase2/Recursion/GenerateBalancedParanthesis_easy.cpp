// https://maang.in/problems/Generate-Balanced-Parenthesis-easy-version-484?resourceUrl=cs99-cp512-pl3524-rs484
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Choice at a Level => Recusion?
int n;
string currSoln="";
int open=0;

void rec(int level){
    // base case
    if(level==n){
        if(open==0) cout << currSoln << "\n";
        return;
    }

    // choices
    // (
    if(n-level-1 > open){
        currSoln.push_back('(');
        open++;
        rec(level+1);
        currSoln.pop_back();
        open--;
    }
    // )
    if(open>0){
        currSoln.push_back(')');
        open--;
        rec(level+1);
        currSoln.pop_back();
        open++;
    }
}

void solve(){
    cin>>n;

    currSoln="";
    open=0;
    rec(0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}