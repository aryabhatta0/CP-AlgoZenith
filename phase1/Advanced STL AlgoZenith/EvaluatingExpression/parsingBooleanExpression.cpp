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
    bool parseBoolExpr(string expression) {
        // using stack to keep track of expression/operators
        // we'll evaluate the expression whenever we encounter ')'
        stack<char> stk;
        
        for (char c : expression) {
            if (c == ',' || c == '(') {
                continue;
            }
            if (c == ')') {
                vector<char> subExpr;
                
                // Pop the sub-expression until we hit an operator
                while (stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                
                // The operator will be the next element on the stack
                char op = stk.top();
                stk.pop();
                
                // Evaluate the expression based on the operator
                char result;
                if (op == '!') {
                    // NOT operator: only one element in subExpr
                    result = (subExpr[0] == 't') ? 'f' : 't';
                } else if (op == '&') {
                    // AND operator: result is 't' only if all subExpr elements are 't'
                    result = 't';
                    for (char e : subExpr) {
                        if (e == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (op == '|') {
                    // OR operator: result is 't' if any subExpr element is 't'
                    result = 'f';
                    for (char e : subExpr) {
                        if (e == 't') {
                            result = 't';
                            break;
                        }
                    }
                }
                
                // Push the result of the sub-expression back to the stack
                stk.push(result);
            } else {
                // For 't', 'f', and operators ('!', '&', '|'), just push them to the stack
                stk.push(c);
            }
        }
        
        // The result of the expression is now on top of the stack
        return stk.top() == 't';
    }
};

// int32_t main() {
//     Solution s;
//     vector<int> nums = {2,1,3,4};
//     int k = 1;
//     cout << s.func() << "\n"; 
//     return 0;
// }