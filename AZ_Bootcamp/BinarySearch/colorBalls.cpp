#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long

// if it's possible to fill mid buckets
// Intuition: Consider a 2d grid with rows as bucket (`mid` rows) and cols as balls (k cols)
// You'll fill each call from top to down with min(mid, freq) balls
// At last, ypu should have total used balls >= k*mid
bool check(int mid, int k, map<int, int>& freq) {
    int usefulBalls = 0;
    for(auto it: freq){
        usefulBalls += min(mid, it.second);
    }

    return usefulBalls >= k*mid;
}

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    
    int lo=0, hi=n;
    int ans=0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid, k, freq)){
            ans=mid;
            lo=mid+1;
        } else hi=mid-1;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
