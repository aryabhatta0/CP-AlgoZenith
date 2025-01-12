// https://leetcode.com/problems/parsing-a-boolean-expression/description/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

/**
You've to evaluate all adjacent braces ( ) 
For that, you'll need the operator mentioned as say &( )    
- Use stack: to trace back
- eval the ( ), put it again to stack
*/

class Solution {
public:
    bool isOp(char ch) {
        return ch=='!' || ch=='&' || ch=='|';
    }
    bool isBool(char ch) {
        return ch=='t' || ch=='f';
    }
    char boolToString(bool a){
        return (a ? 't' : 'f');
    }
    char evaluate(vector<bool> vec, char op) {
        int n=vec.size();
        if(op=='!') return boolToString(!vec[0]);
        else if(op=='&') {
            bool res=vec[0];
            for(int i=1; i<n; i++) {
                res &= vec[i];
            }
            return boolToString(res);
        } else {
            bool res=vec[0];
            for(int i=1; i<n; i++) {
                res |= vec[i];
            }
            return boolToString(res);
        }
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto it: expression) {
            if(it==')') {
                vector<bool> vec;
                while(st.top()!='(') {
                    auto ch = st.top();
                    if(isBool(ch)) {
                        vec.push_back((ch=='t' ? true : false));
                    }
                    st.pop();
                }
                
                st.pop();
                char op = st.top();
                st.pop();

                st.push(evaluate(vec, op));
            } else if(it!=','){
                st.push(it);
            }
        }

        return (st.top()=='t' ? true : false);
    }
};
// int32_t main() {
//     Solution s;
//     vector<int> nums = {2,1,3,4};
//     int k = 1;
//     cout << s.func() << "\n"; 
//     return 0;
// }