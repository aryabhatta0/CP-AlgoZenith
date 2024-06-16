#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
vector<int> arr;

void bin_search(int l, int r, ll k, bool asc){
    while(l<r){
        if(r-l==1){
            if(arr[l]==k){
                cout<<l+1<<" ";
            } else if(arr[r]==k){
                cout<<r+1<<" ";
            }
            return;
        }

        int mid=(l+r)/2;
        if(arr[mid]<k){
            // asc
            if(asc)
                l=mid;
            else
                r=mid;
        } else{
            if(asc)
                r=mid;
            else
                l=mid;
        }
    }

    if(arr[l]==k){
        cout<<l+1<<" ";
    }
    return;
}

// 1 2 5 3 2 1

void solve(){
    int q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    // find p - max pos
    int p;
    // for(int i=0; i<n; i++){
    //     if(arr[i+1]<arr[i]){
    //         p=i;
    //         break;
    //     }
    // }

    // finding peak using binary search
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]>arr[mid+1]){
            p=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    // cout << "p: " << p << "\n";
        

    while(q--){
        ll k; cin>>k;
        bin_search(0, p, k, 1);
        bin_search(p+1, n-1, k, 0);
        cout<<"\n";
    }
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}