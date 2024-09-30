// https://www.interviewbit.com/problems/generate-all-parentheses/submissions/

#include <bits/stdc++.h>
using namespace std;

map<char, int> mp = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
int isValid(string A) {
    stack<int> st;
    for(auto it: A){
        if(mp[it]<0) st.push(mp[it]);
        else {
            if(st.empty() || st.top()+mp[it]!=0) return 0;
            else st.pop();
        }
    }
    
    return st.empty() ? 1 : 0;
}

int main(){
    string A = "()[]{}";
    cout << isValid(A) << "\n";
}
