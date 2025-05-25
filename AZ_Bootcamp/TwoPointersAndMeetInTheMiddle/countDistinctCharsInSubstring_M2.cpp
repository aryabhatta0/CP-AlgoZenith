#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Method2: Offcial Soln way!
// But my M1 soln more intuitive hehe

// Intuition: Think contribution of each a-z char
// Reverse thinking: Find number of substrings a char ch will not be a part of, and subtract from ans
// Max n*(n+1)/2 substrings exists in a n-sized string
void solve(){
    int n; cin>>n;
    string str; cin>>str;

    // assuming each char contributed in all possible substring
    ll ans = 26 * (1LL* n * (n+1))/2;
    // now subtract the substrings each char was not a part of

    vector<int> prev(26, -1);   // last occurence of every char seen

    // substrings b/w curr char and last occurence of it
    for(int i=0; i<n; i++) {
        int len = i - prev[str[i]-'a'] - 1;   
        ans -= (1LL * len * (len+1))/2;     // num of substrings
        prev[str[i]-'a'] = i;
    }

    // substrings b/w each char last occurence to n
    for(int i=0; i<26; i++){
        int len = n - prev[i] - 1; 
        ans -= (1LL * len * (len+1))/2;     // num of substrings
    }

    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}