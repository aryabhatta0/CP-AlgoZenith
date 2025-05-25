#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll a, b;
ll cnt;
vector<int> curr_palindrome;
int max_level, min_level, levels;

bool isPrime(ll n){
    if(n==1) return false;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

bool isPrime(vector<int> &prime){
    ll num = 0;
    for(int i=0; i<prime.size(); i++){
        num = num*10 + prime[i];
    }

    return (num>=a && num<=b && isPrime(num));
}

bool isPalindrome(int n){
    string s = to_string(n);
    int len = s.size();
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}

// 

bool check(int dig, int level){
    if(curr_palindrome.size()==0 && dig==0) return false;

    // int test = levels/2;
    // if(levels%2!=0) test+=1;
    int test = levels%2 ? levels/2+1 : levels/2;
    if(level<test+1) return true;

    if(dig==curr_palindrome[levels-level]) return true;
    return false;
}

void generatePalindromes(int level){
    if(level==levels+1){   
        // cout << level << " curr_palindrome: ";
        // for(auto x : curr_palindrome) cout << x << " "; cout << "\n";

        if(isPrime(curr_palindrome)) cnt+=1;
        return;
    }

    // enumerate choices
    for(int i=0; i<=9; i++){
        if(check(i, level)){
            // make move
            curr_palindrome.push_back(i);    // update curr_palindrome
            generatePalindromes(level+1);    // go to next level (recursion)
            curr_palindrome.pop_back();       // undo move once done with next level exploration
        }
    }     
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    min_level = to_string(a).size();
    max_level = to_string(b).size();

    cnt = 0;
    for(int i=min_level; i<=max_level; i++){
        levels = i;
        curr_palindrome.clear();
        generatePalindromes(1);
    }

    cout << cnt << "\n";
}