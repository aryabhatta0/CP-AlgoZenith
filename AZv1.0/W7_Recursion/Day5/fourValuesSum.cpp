#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(){
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    // cout << "Array: ";
    // for(auto i: a) cout<<i<<" "; cout << "\n";

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll sum = x - a[i] - a[j];
            // cout << "i=" << i << ", j=" << j << ", req sum=" << sum << "\n";
            int l = j+1, r = n-1;
            while(l < r){
                ll curr_sum = a[l] + a[r];
                if(curr_sum == sum){
                    cout << "YES\n";
                    return 0;
                }
                else if(curr_sum < sum) l++;
                else r--;
            }
        }
    }

    cout << "NO\n";
    return 0;
}