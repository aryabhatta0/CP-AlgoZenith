// Why WA?
// Why can't we store 2 things in dp?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;

// final result after merging no more same in every way
// can't we store 2 things pair<int, int> in dp

int n, x, y, z;
vector<int> a;
vector<vector<pair<int, int>>> dp;  // cost, merged val

pair<int, int> rec(int l, int r){
    if(l==r) return make_pair(0, a[l]);
    if(l>r) return make_pair(INF, INF);

    if(dp[l][r]!=make_pair(-1, -1)) return dp[l][r];

    int res=INF, val=INF;
    for(int mid=l; mid<r; mid++){
        // merge l...mid & mid+1...r
        auto t1 = rec(l, mid);
        auto t2 = rec(mid+1, r);

        int cost = t1.first + t2.first;

        // merge this two merged
        // cost += ((sum(l,mid)%100) * (sum(mid+1, r)%100));
        cost += t1.second * t2.second;

        // res = min(res, cost);
        if(res > cost){
            res=cost;
            val = (t1.second*x + t2.second*y + z)%50;
        } else if(res==cost){
            val = min(val, ((t1.second*x + t2.second*y + z)%50));
        }
    }
    return dp[l][r] = make_pair(res, val);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y>>z;
    a.resize(n); 
    for(int i=0; i<n; i++) cin>>a[i];

    // memset(dp, -1, sizeof(dp));
    dp.resize(n+1, vector<pair<int, int>>(n+1, make_pair(-1, -1)));
    cout << rec(0, n-1).first << "\n";
    // cout << rec(0, n-1).first << " " << rec(0, n-1).second << "\n";
    
    // print dp
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j].first << " " << dp[i][j].second << " | ";
        } cout << "\n";
    } cout << "\n";
    
    return 0;

}