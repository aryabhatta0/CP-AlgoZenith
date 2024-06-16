// https://maang.in/problems/Kth-Permutation-hard-version-477?resourceUrl=cs99-cp512-pl3523-rs477
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// (mine)
// Sit with copy and pen to realize:
// At max, only last 13 element gets permuted
// posn of last elem = k / (n-1)! , where n is remaining elem to be placed
// since there fixing an elem can be a fixed pos in (n-1)! ways - bundle!

void solve(){
    int n, k; cin>>n>>k;
    vector<int> arr;
    int it=1;
    while(n>13) {
        cout << it++ << " ";
        n--;
    }
    // n <= 13
    int fact=1;    // initialize with (n-1)!
    for(int i=0; i<n; i++){
        arr.push_back(it++);
        if(i) fact*=i;
    }

    k--;
    vector<int> ans(n); 
    for(int i=0; i<n; i++){
        // find the val to be placed at ans[i]
        ans[i] = arr[k / fact];
        if(i==n-1) break;   // avoiding divide by 0 :)

        // remove the elem at k/fact
        arr.erase(arr.begin() + (k/fact));

        // update k to num'th permulation we want in the new arr
        k %= fact;

        // update fact to new (n-1)!
        fact /= arr.size();
    }

    for(auto it: ans) cout << it << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}