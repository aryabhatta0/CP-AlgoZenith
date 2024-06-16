// https://maang.in/problems/Generate-Balanced-Parenthesis-medium-version-485?resourceUrl=cs99-cp512-pl3524-rs485
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Choice at a Level => Recusion?
int n, k;
string currSoln="";
int open=0;
int depth=0;

void rec(int level){
    // base case
    if(level==n){
        if(open==0 && depth==k) cout << currSoln << "\n";
        return;
    }

    // choices
    // (
    if(n-level-1 > open && open<k){     // open<k to stop depth from inc further
        currSoln.push_back('(');
        open++;
        int last_depth = depth;
        depth=max(open, depth);
        rec(level+1);

        currSoln.pop_back();
        open--;
        depth=last_depth;
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
    cin>>n>>k;

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