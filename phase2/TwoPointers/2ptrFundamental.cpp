// Longest Subarray with <=k zeroes

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Also know the condition to apply two pointers!

// Two Pointer Template
/** 3 things to change:
 * check (next element) is valid
 * insert (next element) to move head
 * remove (tail) to move tail
*/
void TP_AZ(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // DS for two pointers condition checking
    int distinct=0;
    map<int, int> freq;
    //

    // pointers
    int head=-1, tail=0;
    ll ans=0;
    while(tail<n){
        // while there is a next element to take without violating the condition
        while(head+1<n && ( true /**check if next element is valid*/ )){
            head++;
            // insert (head)
            freq[a[head]]++;
            if(freq[a[head]]==1) distinct++;
            //
        }

        // Debug
        // cout << tail << " " << head << ": ";
        // cout << distinct << "\n";

        // update ans accordingly
        ans += head-tail+1;

        // move tail ahead and remove the last element's contribution
        if(head>=tail){
            // remove (tail)
            freq[a[tail]]--;
            if(freq[a[tail]]==0) distinct--;
            //
            tail++;
        } else {
            tail++;
            head=tail-1;
        }

        cout << ans << "\n";
    }
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    // Method 1: me trying az's method
    int l=0, r=0;
    int ans=0, cnt=0;
    while(r<n){
        if(a[r]==0) cnt++;
        while(cnt>k){
            if(a[l]==0) cnt--;
            l++;
        }
        cout << l << " " << r << ": " << cnt << "\n";
        ans=max(ans, r-l+1);
        r++;
    }

    // Method 2: az's method
    int head=-1, tail=0;    // empty subarray initially
    int ans=0, cnt=0;
    while(tail<n){      // generic condition
        while((cnt<k && head<n-1) || (head<n-1 && a[head+1]==1)){
            head++;
            if(a[head]==0) cnt++;
        }
        ans=max(ans, head-tail+1);
        tail++;
        if(a[tail-1]==0) cnt--;
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}