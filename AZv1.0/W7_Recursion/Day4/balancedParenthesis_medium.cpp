#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, k;
vector<char> curr_soln;  // DS to store current solution
vector<char> choices = {'(', ')'};
int depth = 0, curr_depth = 0;

bool check(char ch){
    // cout << "check: ";
    // for(auto x : curr_soln) cout << x << " "; cout << "\n";

    stack<char> s;
    for(auto x : curr_soln){
        if(x=='(') s.push(x);
        else{
            if(s.empty()) return false;
            s.pop();
        }
    }

    if(ch=='(') s.push(ch);
    else{
        if(s.empty()) return false;
        s.pop();
    }
    
    // returning true when there is sufficient space remaining for closing open brackets
    if(s.size()<=(n-curr_soln.size())) return true;
    return false;
}

void rec(int level){
    if(depth>k) return; // not a valid soln

    // base case
    if(level==n){
        // cout << "depth: " << depth << "\n";
        if(depth==k){
            // we have a soln (curr_soln)
            for(int i=0; i<n; i++) cout<<curr_soln[i]; cout << "\n";
        }
        return;
    }

    // enumerate choices
    for(auto ch : choices){
        if(check(ch)){
            // make move
            curr_soln.push_back(ch);    // update curr_soln
            if(ch=='(') curr_depth++;
            else curr_depth--;
            int prev = depth;
            depth = max(depth, curr_depth);

            rec(level+1);               // go to next level (recursion)
            
            curr_soln.pop_back();       // undo move once done with next level exploration
            if(ch=='(') curr_depth--;
            else curr_depth++;
            depth = prev;
        }
    }
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rec(0);

    return 0;
}