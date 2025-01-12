// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
// https://maang.in/problems/Valid-Parentheses-AZ101-348?resourceUrl=cs99-cp510-pl3444-rs348
// Find the minimum number of parentheses you should add to make the parentheses valid.

// The q was a little different. parentheses could be "anywhere".
// Think of CheckValidParentheses and how stack is best in that case?
// Won't this work as well?

// "{(})" this isn't a valid paranthesis, so stack _/
// so depth method like this would fail for checkParantheses

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Not the conventional stack way
// something smarter

// can implement for multiple types of parentheses ({[]})
// open[3]

void solve(){
    string s; cin>>s;
    map<char, int>  mp;
    mp['('] = +1;
    mp[')'] = -1;

    int ans=0;
    int open=0;
    for(auto it: s){
        if(mp[it]>0) open++;
        else {
            if(open>0) open--;
            else ans+=1;
        }
    }
    ans+=open;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}