// https://maang.in/problems/Interesting-Game-76?resourceUrl=cs99-cp510-pl3446-rs76&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first + a.second > b.first + b.second;
}

// Concept: Choose an i so that Ai would be high, and Bi would be high too
// think why? for opponent to not have a chance to choose a high Bi
// maximize Ai + Bi
void solve(){
    int n; cin>>n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++) arr[i] = {a[i], b[i]};
    
    sort(arr.begin(), arr.end(), comp);
    int score1=0, score2=0; bool turn=true;
    for(int i=0; i<n; i++){
        if(turn) score1+=arr[i].first; 
        else score2 += arr[i].second;
        turn = !turn;
    }

    if(score1 > score2) cout << "Alice\n";
    else if(score1 < score2) cout << "Bob\n";
    else cout << "Tie\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}