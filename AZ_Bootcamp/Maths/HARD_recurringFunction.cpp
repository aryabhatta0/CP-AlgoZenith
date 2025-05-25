// https://maang.in/problems/Recurring-Fractions-72?resourceUrl=cs117-cp540-pl3643-rs72&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q. Given two integers representing the numerator and denominator of a fraction, print the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int num, den;
    cin >> num >> den;

    bool neg = false;
    if (num < 0 && den > 0) neg = true;
    if (num > 0 && den < 0) neg = true;

    num = abs(num);
    den = abs(den);

    string ans;
    if (neg) ans.push_back('-');
    
    // Append the integer part
    ans += to_string(num / den);    // if(num<den) phir 0 insert ho jayega
    num = num % den;

    // If there is no remainder, return the result
    if (num == 0) {
        cout << ans << "\n";
        return;
    }

    // Handling the fractional part
    ans.push_back('.');
    unordered_map<int, int> remainderPos; // To track remainders and their positions
    string fracPart;

    int pos = 0; // Position in the fractional part string
    while (num != 0) {
        if (remainderPos.find(num) != remainderPos.end()) {
            // A repeating remainder has been found
            fracPart.insert(remainderPos[num], "(");
            fracPart.push_back(')');
            break;
        }

        // Store the position of the current remainder
        remainderPos[num] = pos++;
        num *= 10;
        fracPart += to_string(num / den);
        num %= den;
    }

    ans += fracPart;
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int t;
    cin >> t; 
    while (t--) solve();
    
    return 0;
}
