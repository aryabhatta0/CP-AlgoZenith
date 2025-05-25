#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[100001];
ll func(ll x){ // count number of subarray with sum<=x
   ll cnt = 0;
   ll currSum = 0;
   ll start = 0;
   ll current = 0;
   while(current<n){
       currSum+=arr[current];
       while(start<=current and currSum>x){
           currSum-=arr[start];
           start++;
       }
       cnt+=(current-start+1);
       current++;
   }
   return cnt;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       cin>>n;
       ll low = 0,high = 0;
       for(ll i=0;i<n;i++){
           cin>>arr[i];
           high+=arr[i];
       }
       ll ans = -1;
       ll total = (n*(n+1))/2;
       ll median = (total+1)/2;
       while(low<=high){
           ll mid = (low+high)/2;
           ll cntSub = func(mid);
           if(cntSub>=median)
               high = mid-1,ans = mid;
           else
               low = mid+1;
       }
       cout<<ans<<"\n";
   }
}