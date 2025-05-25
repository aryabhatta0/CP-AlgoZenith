#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

bool isPalindrome(int n){
    string s = to_string(n);
    int len = s.size();
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b; cin>>a>>b;

    // find count of prime palindromes in range [a, b]
    // 1. find all primes in range [a, b]
    // 2. check if prime is palindrome
    // 3. count

    int count = 0;
    for(int i=a; i<=b; i++){
        if(isPalindrome(i) && isPrime(i)) count++;
    }

    cout << count << "\n";
}