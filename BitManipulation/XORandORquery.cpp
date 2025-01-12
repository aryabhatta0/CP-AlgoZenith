#include<bits/stdc++.h>
using namespace std;
#define ll long long

/** Concept: Bit-by-bit analysis
 * "Bit expressions are sum independent on each bit"
 * Deciding if ith bet will be set in x1,x2,x3 and adding their contribution !
 */

void solve(){
     int n; cin>>n;
     vector<int> arr(n);
     for(int i=0; i<n; i++) cin>>arr[i];

     // prefix sum to find num with ith set bit in [Al, Ar]
     // smart. precomputing since we'll need this in O(1) computation later.
     vector<vector<int>> pre(n, vector<int>(31, 0));
     for(int i=0; i<31; i++){
          for(int j=0; j<n; j++){
               pre[j][i] = j==0 ? 0 : pre[j-1][i];
               if((arr[j] & (1<<i)) != 0) pre[j][i]++;
          }
     }

     int q; cin>>q;
     while(q--){
          int l, r; cin>>l>>r;
          l--; r--;      // 0-based index

          // bit-by-bit anyalysis
          ll ans=0;
          int range = r-l+1;
          for(int i=0; i<31; i++){
               // cnt num with ith set bits in [Al, Ar]     - O(1)
               int cnt = pre[r][i] - (l==0 ? 0 : pre[l-1][i]);

               /** deciding if ith bet will be set in x1,x2,x3 and adding their contribution */
               // and    - unset bit only if cnt==0
               if(cnt!=0) ans += (1LL<<i);
               // or     - unset if all 1
               if(cnt!=range) ans += (1LL<<i);
               // xor    
               // - zyada set hai, toh tum unset kar do
               // - kam set hai, toh tum bhi set kar do
               if(cnt < (range/2.0)) ans += (1LL<<i);
          }
          cout << ans << "\n";
     }
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
     int t; cin>>t; while(t--)
     solve();
     return 0;
}