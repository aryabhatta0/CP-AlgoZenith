// https://maang.in/problems/All-Permutations-475?resourceUrl=cs99-cp512-pl3522-rs475
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;

// Prb could be divided into levels
// in the sense that, we need to put a val at each ind (levels)
// out of the choices (array) given
// ensure the val doesn't get repeated for the check

vector<int> currSoln;
map<int, int> freq;     // will be using this for both storing choices and check
// since why to repeat already chosen vars

void rec(int level){
    // base case
    if(level==n) {
        // print soln
        for(auto it: currSoln) cout << it << " ";
        cout << "\n";
        return;
    }

    // enumerate over choices
    for(auto it: freq){
        if(it.second > 0) {
            int choice = it.first;

            currSoln.push_back(choice);
            freq[choice]--;
            if(freq[choice]==0) freq.erase(choice);
            rec(level+1);

            currSoln.pop_back();
            freq[choice]++;
        }
    }
}

void solve(){
    cin>>n;

    freq.clear();
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        freq[x]++;
    }

    rec(0);
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}