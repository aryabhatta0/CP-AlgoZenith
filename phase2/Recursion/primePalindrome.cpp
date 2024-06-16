#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int a, b;
string currAns="";

ll cnt=0;   // counting Prime Palindromes 

bool checkPrime(int n){
    if(n<=1) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}

// generate palindromes of length len
void rec(int lev, int len){
    // base case
    if(lev==len){
        // cout << "palindrome: " << currAns << "\n";
        // if (currAns != "") {
        //     try {
        //         ll ans = stoll(currAns);
        //         if (ans >= a && ans <= b && checkPrime(ans)) cnt++;
        //     } catch (const out_of_range& e) {
        //         // Handle the case where stoll conversion is out of range
        //     }
        // }
        // return;

        try {
            int ans = stoi(currAns);
            if(ans>=a && ans<=b && checkPrime(ans)) cnt++;
        } catch (...){
            
        }
        return;
    }

    // choices
    if(lev >= ceil(len/2.0)){
        // we don't really have a choice
        string rev = currAns;
        if(len%2!=0) {
            rev.pop_back();
        } 
        reverse(rev.begin(), rev.end());

        string temp = currAns;
        currAns += rev;
        rec(len, len);
        currAns = temp;
    } else {
        for(char ch='0'; ch<='9'; ch++){
            if(lev==0 && ch=='0') continue;

            // no need of a check
            currAns.push_back(ch);
            rec(lev+1, len);
            currAns.pop_back();
        }
    }
}

void solve(){
    // we can't check all the primes under 1e9
    // generator => palindrome

    cin>>a>>b;
    int minLen=to_string(a).length(), maxLen=to_string(b).length();
    cnt=0;
    for(int i=minLen; i<=maxLen; i++){
        // cout << "For len=" << i << " : \n";
        currAns="";
        rec(0, i);
    }

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}