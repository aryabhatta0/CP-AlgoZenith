// https://maang.in/problems/Good-Pairs-AZ101-377?resourceUrl=cs99-cp512-pl3462-rs377
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// The given inequality is the same as: (Ai-Bi) + (Aj-Bj) > 0. Let Ci=Ai-Bi, you just need to find pairs such that: Ci+Cj > 0

void solve(){
    int n; cin>>n;
    vector<int> diff(n);

    for(int i=0; i<n; i++) cin>>diff[i];
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        diff[i] -= x;
    }

    // since addition is commutative just sort the elements of the array C
    // after all, we have to check each pair, so sorting won't effect
    sort(diff.begin(), diff.end());
    ll ans=0;
    for(int i=0; i<n-1; i++){
        // ans += distance(upper_bound(diff.begin()+i+1, diff.end(), -diff[i]), diff.end());
        int curr = diff.end() - upper_bound(diff.begin() + i + 1, diff.end(), -diff[i]);
        // cout << "Cnt for i=" << i << " d[i]=" << diff[i] << " is: " << curr << "\n";
        ans += curr;
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