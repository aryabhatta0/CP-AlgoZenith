// https://maang.in/problems/Interesting-Game-76?resourceUrl=cs99-cp510-pl3446-rs76
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Concept: It can be proven that the optimal move for the current player is to always choose the first unused element having the maximal value for Ai + Bi
// , as the player will either add the largest number of points to their own score or block the opposing player from ever receiving a large number of points.

void solve(){
    int n; cin>>n;
    priority_queue<pair<int, int>> pq;  // sum, ind
    int a[n], b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n; i++) pq.push({a[i]+b[i], i});

    int sumA=0, sumB=0;
    for(int i=0; i<n; i++){
        auto it = pq.top();
        pq.pop();

        if(i%2==0) sumA+= a[it.second];
        else sumB += b[it.second];
    }

    if(sumA>sumB) cout << "Alice\n";
    else if(sumA<sumB) cout << "Bob\n";
    else cout << "Tie\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}