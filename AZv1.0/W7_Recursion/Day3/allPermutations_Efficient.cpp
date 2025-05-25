#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
map<int, int> freq; // used in check function

vector<int> curr_soln;  // DS to store current solution
// set<vector<int>> all_solns; // DS to store all solutions

void rec(int level){    // recursion with levels
    // cout << "level: " << level << " => ";
    // for(auto x : curr_soln) cout << x << " "; cout << "\n";

    // base case
    if(level==n){
        // we have a soln (curr_soln)
        for(int i=0; i<n; i++) cout<<curr_soln[i]<<" ";
        cout << "\n";
        // all_solns.insert(curr_soln);     // no chance of duplicate solns here
        return;
    }

    // enumerate choices
    for(auto ch : freq){
        // easy check for valid choice
        if(ch.second > 0){
            // make move
            curr_soln.push_back(ch.first);    // update curr_soln
            freq[ch.first]--;

            // go to next level (recursion)
            rec(level+1);

            // undo move once done with next level exploration
            freq[ch.first]++;
            curr_soln.pop_back();
        }

        // check if valid choice based on previous choices (curr_soln)
        // if(check(ch)){
        //     // make move
        //     curr_soln.push_back(ch);    // update curr_soln
        //     rec(level+1);               // go to next level (recursion)
        //     curr_soln.pop_back();       // undo move once done with next level exploration
        // }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        freq[temp]++;
    }
    rec(0);

    return 0;
}