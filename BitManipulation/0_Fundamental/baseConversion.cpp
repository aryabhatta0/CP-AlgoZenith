#include <bits/stdc++.h>
using namespace std;

// Characters to represent digits beyond 9 (for bases up to 36)
string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// convert any decimal number to base b
string decimalToBase2(int x, int b){
    string res;
    if(x/b) {
        res = decimalToBase2(x/b, b);
    }

    res.push_back(digits[x%b]);
    return res;
}

// iterative
string decimalToBase(int x, int b){
    string res;
    while(x>0){
        res.push_back(digits[x%b]);
        x /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}

int charToValue(char ch) {
    if(ch>='0' && ch <= '9') return ch-'0';
    else {  // ch >= 'A' && ch <='Z
        return ch - 'A'+ 10;
    }
}
int baseToDecimal(string s, int b){
    int n=s.size();
    int num=0;
    for(int i=s.size()-1; i>=0; i--){
        num += charToValue(s[i]) * pow(b, n-1-i);
    }
    return num;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cout << decimalToBase(100, 16) << "\n";
    cout << baseToDecimal("64", 16) << "\n";
    return 0;
}