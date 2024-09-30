// https://maang.in/problems/Subset-Sum-Queries-760?resourceUrl=cs100-cp506-pl3404-rs760

#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

/* Concepts:
    1. Check if a subset with target sum exists in an array
    2. Generating the solution
*/

int dp[101][100100];

// if a subset with sum=tar exists in lev...n
bool rec(int lev, int tar, vector<int> &arr){
    int n = arr.size();

    // base case
    if(tar<0) return 0;
    if(tar==0) return 1;
    if(lev>=n) return 0;

    // cache check
    if(dp[lev][tar]!=-1) return dp[lev][tar];

    // transition, save and return
    return dp[lev][tar] = rec(lev+1, tar, arr) | rec(lev+1, tar-arr[lev], arr);
}

// generate the result
vector<int> result;
void generate(int lev, int tar, vector<int> &arr){

    // decide whether to pick / skip, and add to result
    if(tar==0) return;
    // int n=arr.size();
    // if(lev==n) return;

    // skip
    if(rec(lev+1, tar, arr)) generate(lev+1, tar, arr);
    // pick
    else if(rec(lev+1, tar-arr[lev], arr)) {
        result.push_back(lev);
        generate(lev+1, tar-arr[lev], arr);
    } 
    else {
        result.push_back(-1);
        return;
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.

    vector<vector<int>> ans;

    // cache a dp that stores if a given sum exists in lev....N
    memset(dp, -1, sizeof(dp));

    for(auto sum: queries){
        // return subset with sum as it
        // generate such solution
        result.clear();
        generate(0, sum, arr);
        ans.push_back(result);
    }

    return ans;
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
