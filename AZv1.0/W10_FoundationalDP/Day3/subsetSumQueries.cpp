#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

// dp[lev][sum]: if sum can be made from subset of arr[lev...n-1]
// return dp[0][sum] for a query
// caching across queries _/ 

int dp[101][100100];

int rec(int lev, int sum, vector<int> &arr){
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(lev==arr.size()) return 0;

    if(dp[lev][sum]!=-1) return dp[lev][sum];

    // choices
    // pick
    int res1 = rec(lev+1, sum-arr[lev], arr);
    // skip
    int res2 = rec(lev+1, sum, arr);

    if(res1 | res2) return dp[lev][sum]=1;
    return dp[lev][sum]=0;
}

vector<int> getSubset(int lev, int sum, vector<int> &arr){
    if(sum<0) return {};
    if(sum==0) return {};
    if(lev==arr.size()) return {};

    vector<int> ans;

    // pick
    if(rec(lev+1, sum-arr[lev], arr)==1) {
        ans.push_back(lev);
        vector<int> temp = getSubset(lev+1, sum-arr[lev], arr);
        for(auto x: temp) ans.push_back(x);
        return ans;
    }

    // skip
    if(rec(lev+1, sum, arr)==1) {
        ans = getSubset(lev+1, sum, arr);
        return ans;
    }

    return {};
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> res;

    for(auto tar: queries){
        if(rec(0, tar, arr)==1){
            res.push_back(getSubset(0, tar, arr));
        } 
        else res.push_back({-1});
    }

    // print res
    // cout << "res: \n";
    // for(auto x: res){
    //     for(auto y: x) cout << y << " ";
    //     cout << "\n";
    // } cout << "\n";

    return res;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}