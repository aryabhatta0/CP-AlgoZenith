// https://maang.in/problems/Evaluating-Boolean-Expressions-91?resourceUrl=cs117-cp540-pl3642-rs91&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// A valid expression is a string of the form ‘([valid expression][operator][valid expression])’
// Given a valid expression, you have to tell the minimum number of characters to modify such that the result of the given expression is a valid expression that does not depend on x
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool getRes(char exp1, char op, char exp2, bool val){
    bool val1;
    if(exp1=='0') val1=0;
    else if(exp1=='1') val1=1;
    // else if(exp1=='x') val1=val;
    // else val1=!val;

    bool val2;
    if(exp2=='0') val2=0;
    else if(exp2=='1') val2=1;
    // else if(exp2=='x') val2=val;
    // else val2=!val;

    if(op=='|') return val1 | val2;
    else if(op=='&') return val1 & val2;
    else if(op=='^') return val1 ^ val2;
}

// evaluate str with x as val
bool evaluate(string& str, bool val){
    stack<char> st;
    for(auto it: str){
        if(it == '(') continue;
        if(it == ')') {
            char exp2 = st.top(); st.pop();
            char op = st.top(); st.pop();
            char exp1 = st.top(); st.pop();

            char res = '0' + getRes(exp1, op, exp2, val);
            st.push(res);
        } else {
            // st.push(it);
            if(it=='x') st.push('0' + val);
            else if(it=='X') st.push('0' + !val);
            else st.push(it);
        }
    }
    return st.top()-'0';
}

// Obsv: ans will always be either 0 or 1
/** `Exp1 Op Exp2`
- The exp's will evaluate to either 0, 1, x or, X
- and u just need to pick appropriate oper to make the result independent (just 1 change)
*/
void solve(){
    string str; cin>>str;

    bool val1 = evaluate(str, 0);
    bool val2 = evaluate(str, 1);
    if(val1==val2) cout << "0\n";
    else cout << "1\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}