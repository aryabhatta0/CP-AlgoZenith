#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// returns no. of painters req to paint the board in mid time
int check(vector<int> a, int n, int mid){
    int curr=0;
    int painters=0;
    for(int i=0; i<n; i++){
        curr+=a[i];
        if(curr>mid){
            painters++;
            curr=a[i];
        }
    }
    if(curr) painters++;
    return painters;
}

void solve(int k){
    int n=6;
    // cin>>n>>k;
    vector<int> a={5,2,7,3,1,8};
    int l=1, r=0;
    for (int i=0; i<n; i++) {
        // cin>>a[i];
        l=max(l, a[i]); // min poss ans
        r+=a[i];        // max time possible
    }

    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        // cout << l << " " << r << " " << mid << " check: " << check(a, n, mid) << "\n";
        if(check(a, n, mid) <= k){
            // l=mid+1;
            r=mid-1;
            ans=mid;
        } else{
            // r=mid-1;
            l=mid+1;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve(1);
    solve(2);
    solve(3);
    solve(4);
    solve(5);
    solve(6);
    // }
    return 0;
}