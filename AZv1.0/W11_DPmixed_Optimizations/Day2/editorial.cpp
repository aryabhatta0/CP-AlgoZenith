#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int pw(int a,int b,int p){
   if(b==0)return 1;
   int t=pw(a,b/2,p);
   t=(t*t)%p;
   if(b%2)return (a*t)%p;
   return t;
}
int dp[1000001][5];
signed main(){
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       dp[0][0] = 1;
       for (int i = 1; i <= 1000000; ++i) {
           for (int j = 0; j <= 4; ++j) {
               // 0100
               vector<int> v;
               if(j == 0) {
                   v = {0, 2};
               }
               else if(j == 1) {
                   v = {0,1};
               }
               else if(j == 2) {
                   v = {1, 3};
               }
               else if(j == 3) {
                   v = {2};
               }
               else {
                   v = {3, 4, 4};
               }
               for (int k:v) {
                   dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
               }
           }
       }
   int t;
   cin >> t;
   while(t--) {
       int n;
       cin>>n;
       cout << (pw(2,n,mod) - dp[n][4] + mod)%mod << "\n";
   }
   return 0;
}