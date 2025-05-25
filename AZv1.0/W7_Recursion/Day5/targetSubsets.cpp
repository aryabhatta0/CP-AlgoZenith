#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// subsets with target sum
// we have choice of either including or excluding each element - use recursion with levels

// This is same as generating all subsets
// 2^n & n<=35 giving TLE

int n, x;
vector<int> a;
// vector<int> curr_soln;
ll sum = 0, ans = 0;

// level: at each index we are either taking or not taking the element
void rec(int level, int end, vector<int>& subsetSum){
    if(sum > x) return;

    // base case
    if(level == end){
        if(sum <= x){
            subsetSum.push_back(sum);
            // ans++;
            // cout << "curr_soln: ";
            // for(int i=0; i<curr_soln.size(); i++) cout<<curr_soln[i]<<" ";
            // cout<<"\n";
        }
        return;
    }

    // enumerate choices
    // for(int i=level; i<n; i++){
    //     // include
    //     if(sum + a[i] <= x){
    //         sum += a[i];
    //         curr_soln.push_back(a[i]);
    //         rec(i+1);
    //         sum -= a[i];
    //         curr_soln.pop_back();
    //     }

    //     // exclude
    //     rec(i+1);
    // }

    // include
    if(sum + a[level] <= x){
        sum += a[level];
        // curr_soln.push_back(a[level]);
        rec(level+1, end, subsetSum);
        sum -= a[level];
        // curr_soln.pop_back();
    }

    // exclude
    rec(level+1, end, subsetSum);
}

void solve(){
    cin>>n>>x;
    a.clear(); a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // curr_soln.clear();
    sum = 0;
    vector<int> subsetSum1;
    rec(0, n/2, subsetSum1);

    // curr_soln.clear();
    sum = 0;
    vector<int> subsetSum2;
    rec(n/2, n, subsetSum2);

    ans = 0;
    sort(subsetSum2.begin(), subsetSum2.end());
    for(auto i: subsetSum1){
        int rem = x - i;
        int idx = upper_bound(subsetSum2.begin(), subsetSum2.end(), rem) - subsetSum2.begin();
        ans += idx;
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}