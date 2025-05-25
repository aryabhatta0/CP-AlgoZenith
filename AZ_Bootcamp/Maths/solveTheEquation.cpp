#include<bits/stdc++.h>
using namespace std;
#define int long long 

// return true if op1 has higher precedence
bool precedence(char op1, char op2){
    if(op1=='/') return 1;
    else if(op2=='/') return 0;

    if(op1=='*') return 1;
    else if(op2=='*') return 0;

    return 1;
}

int binpow(int a, int n, int p) {
    if(n == 0) return 1;

    int temp = binpow(a, n / 2, p);
    temp = (temp * temp) % p;
    
    if(n % 2 == 1) temp = (temp * a) % p;
    return temp;
}

int modiv(int a, int p) {
    return binpow(a, p - 2, p);
}

int getVal(int a, int b, char op, int p) {
    if(op == '+') return (a + b) % p;
    if(op == '-') return (a - b + p) % p;  // Adjust for negative result
    if(op == '*') return (a * b) % p;
    if(op == '/') return (a * modiv(b, p)) % p;
    return 0;
}

void solve() {
    string s;
    cin.ignore();       // important for getline
    getline(cin, s);

    vector<int> val;
    vector<char> oper;
    string temp = "";

    for(char ch : s) {
        if(isdigit(ch)) temp += ch;
        else if(!temp.empty()) {
            val.push_back(stoi(temp));
            temp = "";
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/') oper.push_back(ch);
    }
    if(!temp.empty()) val.push_back(stoi(temp));  // Handle modulus 'p'

    int a = val[0], b = val[1], c = val[2], p = val[3];
    char op1 = oper[0], op2 = oper[1];

    int ans;
    if(precedence(op1, op2)) {
        ans = getVal(a, b, op1, p);
        ans = getVal(ans, c, op2, p);
    } else {
        ans = getVal(b, c, op2, p);
        ans = getVal(a, ans, op1, p);
    }

    cout << (ans + p) % p << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}