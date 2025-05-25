#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int n;
int arr[1001];

int len[1001];  // len[i] = LIS ending at i
ll cnt[1001];  // cnt[i] = number of LIS ending at i

// iterative DP
void rec(){
    
    int lis=1;
    for(int i=0; i<n; i++){
        len[i]=1;
        cnt[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                // len[i] = max(len[i], len[j]+1);
                if(len[i] < len[j]+1){
                    len[i] = len[j]+1;
                    // cnt[i] = 1;
                    cnt[i] = cnt[j];
                } 
                // else if(len[i]==len[j]+1) cnt[i]++;
                else if(len[i]==len[j]+1) cnt[i]+=cnt[j];
            } 
            // else if(arr[j]==arr[i]) // can't be extended
        }
        lis = max(lis, len[i]);
    }

    // cout << "len: ";
    // for(int i=0; i<n; i++) cout << len[i] << " "; cout << "\n";
    // cout << "cnt: ";
    // for(int i=0; i<n; i++) cout << cnt[i] << " "; cout << "\n";

    ll ans=0;
    for(int i=0; i<n; i++){
        if(len[i]==lis) ans+=cnt[i];
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>arr[i];

        for(int i=0; i<n; i++){
            len[i] = 1;
            cnt[i] = 1;
        }

        rec();
    }
}