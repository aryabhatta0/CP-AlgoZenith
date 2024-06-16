// https://maang.in/problems/Minimise-Max-Diff-46?resourceUrl=cs99-cp512-pl3460-rs46
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// check if max_gap is possible after adding k points
bool check(vector<int> arr, int gap, int n, int k){

    for(int i=1; i<n; i++){
        int curr_gap = arr[i]-arr[i-1];
        if(curr_gap > gap){
            if(k<=0) return 0;  // if there is no point to fill gap

            int new_points = curr_gap/gap;;
            if((curr_gap % gap) == 0) new_points-=1;
            k -= new_points;

            if(k<0) return 0;            
        }
    }
    return 1;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // k<=1e9 => bS; constraints can also give an idea
    // think if we can check 'ans' could be max gap as well
    // look at monotonicity - if ans is possible, ans+1 as well

    // lo = current max gap ? (that we've to minimize)
    int lo=1, hi=1e9;   // lo=1 since ans/gap can't be 0
    int ans=-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(arr, mid, n, k)){
            hi=mid-1;
            ans=mid;
        } else {
            lo=mid+1;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}