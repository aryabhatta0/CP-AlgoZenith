// TODO: Can be optimized by not iterating over already made choices

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
multiset<int> a;    // helpful in enumerating choices
map<int, int> freq; // used in check function

vector<int> curr_soln;  // DS to store current solution
set<vector<int>> all_solns; // DS to store all solutions

// check if ch is valid choice based on previous choices (curr_soln)
bool check(int ch){
    int cnt = 1;    // 1 to be added
    for(auto x : curr_soln){
        if(x==ch) cnt++;
    }
    return cnt <= freq[ch];
}

void rec(int level){    // recursion with levels
    // cout << "level: " << level << " => ";
    // for(auto x : curr_soln) cout << x << " "; cout << "\n";

    // base case
    if(level==n){
        // we have a soln (curr_soln)
        // for(int i=0; i<n-1; i++) cout<<curr_soln[i]<<" ";
        // cout<< curr_soln[n-1] << "\n";
        all_solns.insert(curr_soln);
        return;
    }

    // enumerate choices
    for(auto ch : a){
        // check if valid choice based on previous choices (curr_soln)
        if(check(ch)){
            // make move
            curr_soln.push_back(ch);    // update curr_soln
            rec(level+1);               // go to next level (recursion)
            curr_soln.pop_back();       // undo move once done with next level exploration
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    a.clear(); freq.clear(); curr_soln.clear(); all_solns.clear();
    cin>>n;
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        a.insert(temp);
        freq[temp]++;
    }
    rec(0);

    for(auto x : all_solns){
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;
        // for(int i=0; i<n-1; i++) cout<<x[i]<<" ";
        // cout<< x[n-1] << "\n";
    }

    return 0;
}