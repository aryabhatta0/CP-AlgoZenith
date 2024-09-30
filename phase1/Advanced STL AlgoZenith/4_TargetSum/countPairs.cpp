#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Key Idea: 2 ptrs (one from start, another from end)
// 2 pointers - O(nlogn + n)
ll countPairs(vector<int> arr, int x){
    int n=arr.size();

    sort(arr.begin(), arr.end());
    int i=0, j=n-1;
    ll ans=0;
    while(i<j){
        if(arr[i]+arr[j]<=x){
            ans+=j-i;   // all pairs containing a[i]
            i++;
        } else {
            j--;    // decrement the sum
        }
    }

    // (i,j) and (j,i) are counted separately
    return 2*ans;
}

// binary search - O(nlogn + nlogn)
ll countPairs2(vector<int> arr, int x){
    int n=arr.size();

    sort(arr.begin(), arr.end());
    ll ans=0;
    for(int i=0; i<n; i++){
        // cnt of elements <= x
        int cnt = upper_bound(arr.begin(), arr.end(), x-arr[i]) - arr.begin();
        if(x-arr[i] >= arr[i]) ans += cnt-1;
        else ans += cnt;
    }

    // (i,j) and (j,i) are counted separately
    return ans;
}

void solve(){
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout << countPairs(a, x) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}