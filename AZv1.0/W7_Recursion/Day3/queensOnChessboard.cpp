#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// How is it a recursion problem?
// U have levels (rows >> individual blocks) 
// Place one queen, call recursion for remaining levels

char a[8][8];
ll ans = 0;

// DS to store current solution
vector<int> curr_soln;  // indices represent rows, values represent cols

// What if we try to return number of solutions in rec?
// What will be the base case?

// check if a new queen can be placed at (level, col)
bool check(int level, int col){
    if(a[level][col]=='*') return false;
    for(int i=0; i<level; i++){
        // check if there is a queen in same col
        if(curr_soln[i]==col) return false;

        // check if there is a queen in same diagonal
        if(abs(curr_soln[i]-col) == abs(i-level)) return false;
    }

    return true;
}

// This way we are incrementing global ans on reaching last level
void rec(int level) {
    // base case
    // since level 7 means we now have to place queen in the last (8th) row
    if(level==8){
        ans++;
        return;
    }

    // enumerate choices
    for(int col=0; col<8; col++){
        // check if valid choice based on previous choices (curr_soln)
        if(check(level, col)){
            // make move
            curr_soln.push_back(col);    // update curr_soln
            rec(level+1);               // go to next level (recursion)
            curr_soln.pop_back();       // undo move once done with next level exploration
        }
    }

    return;
}

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) cin>>a[i][j];
    }

    // print
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }



    // call rec
    ans = 0;
    rec(0);
    cout << ans << "\n";
    
    return 0;
}