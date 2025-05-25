// https://maang.in/problems/Count-Distinct-Char-in-Substrings-62?resourceUrl=cs117-cp540-pl3647-rs62&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Q. Score of a string is the number of distinct characters present in the string.
// Find the sum of the score of all substring of S?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Intution: Think how many substrings each char will contribute to !
void solve(){
    int n; cin>>n;
    string str; cin>>str;

    vector<int> prev(n);
    map<char, int> mp;
    for(int i=0; i<n; i++){
        if(mp.find(str[i]) == mp.end()) prev[i]=-1;
        else prev[i] = mp[str[i]];

        mp[str[i]] = i;
    }

    // Add individual char contributions
    /** str[i] will contribute to all substr staring b/w (prev[i], i] and ending anywhere after i [i, n) */

    ll ans=0;
    for(int i=0; i<n; i++){
        int charsOnLeft = i-prev[i];
        ans += (1LL * charsOnLeft * (n-i));
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}