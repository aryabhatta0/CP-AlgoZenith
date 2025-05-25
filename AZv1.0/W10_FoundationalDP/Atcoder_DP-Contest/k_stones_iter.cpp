#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Doubt: Iterative v/s Recursive DP
// memory crash on recursive??

int n, k;
vector<int> a;
vector<int> dp;

int solve(){
    dp[0]=0;
    for(int i=1; i<=k; i++){
        for(auto it: a){
            if(i-it<0) break;
            if(dp[i-it]==0) {
                dp[i]=1;
                break;
            }
        }
    }

    return dp[k];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];
    dp.resize(k+1, 0);
    if(solve()==1) cout << "First\n";
    else cout << "Second\n";
    return 0;
}