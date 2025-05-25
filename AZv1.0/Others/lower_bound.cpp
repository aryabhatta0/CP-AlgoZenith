#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int lower_bound(vector<int> &a, int x){
    int l=0, r=a.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x){
            ans=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    return ans;
}    

void solve(){
    vector<int> a={1,2,3,4,5,7,8,8,9,10};
    int n=a.size();
    
    cout << lower_bound(a, 8) << "\n";
    cout << lower_bound(a, 6) << "\n";
    cout << lower_bound(a, 3) << "\n";
    cout << lower_bound(a, 11) << "\n";
    cout << lower_bound(a, 0) << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    // return 0;
}