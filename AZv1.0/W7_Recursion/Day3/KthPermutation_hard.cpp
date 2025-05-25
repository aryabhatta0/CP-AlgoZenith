#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k;

    // find out the farthest index from last that will change/permute
    int idx = 1;
    float temp = k;
    while(temp > 1) {
        temp /= idx+1;
        idx++;
    }
    // cout << "idx: " << idx << "\n";
    // idx=3;

    int asize = max(0, n-idx), bsize = min(n, idx);
    vector<int> a(asize);
    vector<int> b(bsize);
    for(int i=0; i<asize; i++) a[i] = i+1;
    for(int i=0; i<bsize; i++) b[i] = i+asize+1;

    // for(auto x : a) cout << x << " "; 
    // // cout << "\n";
    // for(auto x : b) cout << x << " ";
    // cout << "\n";

    // permute b only
    k--;    // 1st permutation is arr itself
    while(k--) {
        next_permutation(b.begin(), b.end());
        // for(int i=0; i<n; i++) cout<<a[i]<<" ";
        // cout<<"\n";
    }

    // print a then b
    for(auto x : a) cout << x << " "; 
    for(auto x : b) cout << x << " ";
    cout << "\n";

    // print all permutations
    // do {
    //     for(int i=0; i<n; i++) cout<<a[i]<<" ";
    //     cout<<"\n";
    // } while(next_permutation(a.begin(), a.end()));

    return 0;
}