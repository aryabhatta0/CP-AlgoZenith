#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    int n; cin>>n;
    string str; cin>>str;

    vector<int> prev(n, -1);    // last occurence of char at str[i]
    map<char, int> mp;  // {char, index}
    mp[str[0]]=0;
    for(int i=1; i<n; i++){
        if(mp.find(str[i])!=mp.end()){
            prev[i] = mp[str[i]];
        }
        mp[str[i]]=i;
    }

    mp.clear();
    vector<int> next(n, n);    // next occurence of char at str[i]
    mp[str[n-1]]=n-1;
    for(int i=n-2; i>=0; i--){
        if(mp.find(str[i])!=mp.end()){
            next[i] = mp[str[i]];
        }
        mp[str[i]]=i;
    }

    // Add individual char contributions
    /** str[i] will contribute to all substr staring b/w (prev[i], i] and ending in [i, next[i]) */

    // compute ans
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += (i - prev[i]) * (next[i] - i);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}