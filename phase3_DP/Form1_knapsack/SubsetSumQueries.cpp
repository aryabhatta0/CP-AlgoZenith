#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

// dp[i][sum]: there exists a subset with sum s in i...n-1
// ans = dp[0][sum] for each query
// caching across queries _/ 

/*
 The best thing was how dp[][] is being used to find the subset with given target!
 coz just dp can only give u if an ans exist or the count of it, but not the exact ans.
*/

int dp[101][100100];

// if there is a subset in lev....n-1 with sum=sum
bool rec(int lev, int sum, vector<int> &arr){
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(lev==arr.size()) return 0;

    if(dp[lev][sum]!=-1) return dp[lev][sum];

    // choices
    // pick
    int res1 = rec(lev+1, sum-arr[lev], arr);
    // skip
    int res2 = rec(lev+1, sum, arr);

    return dp[lev][sum]= res1 | res2;
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

// iterative approach
vector<int> getSubset(int sum, vector<int> arr){
    vector<int> subset;

    for(int i=0; i<arr.size(); i++){
        if(rec(i+1, sum-arr[i], arr)){      // pick
            subset.push_back(i);
            sum-=arr[i];
        }
    }
    return subset;
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> res;

    for(auto tar: queries){
        if(rec(0, tar, arr)==1){
            // res.push_back(getSubset(0, tar, arr));
            res.push_back(getSubset(tar, arr));
        } 
        else res.push_back({-1});
    }

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