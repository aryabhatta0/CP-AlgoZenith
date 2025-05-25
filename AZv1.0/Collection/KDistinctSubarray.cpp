#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// O(nlogn)
void TP_AZ(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // DS for two pointers condition checking
    int distinct=0;
    map<int, int> freq;

    // pointers
    int head=-1, tail=0;
    ll ans=0;
    while(tail<n){
        // while there is a next element to take without violating the condition
        // while(head+1<n && ( (distinct<k) || (distinct==k && freq[a[head+1]]>0) )){
        while(head+1<n && ( (freq[a[head+1]]==0 && distinct<k) || (freq[a[head+1]]>0 && distinct<=k) )){
            head++;
            freq[a[head]]++;
            if(freq[a[head]]==1) distinct++;
        }

        // Debug
        // cout << tail << " " << head << ": ";
        // cout << distinct << "\n";

        // update ans accordingly
        ans += head-tail+1;  // no. of subarrays starting at tail 

        // move tail ahead and remove the last element's contribution
        if(head>=tail){
            freq[a[tail]]--;
            if(freq[a[tail]]==0) distinct--;
            tail++;
        } else {
            tail++;
            head=tail-1;
        }

        cout << ans << "\n";
    }
}

// subarrays ending at r than starting at l
void old_mine(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
	
    int l=0, r=0;
    ll ans=0;
    unordered_map<int, int> mp;  // freq of elems b/w [l,r]
    while(r<n){
        mp[a[r]]++;
        while(mp.size()>k){
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        ans += r-l+1;  // no. of subarrays ending at r
        // ans++;
        // cout<<l<<" "<< r << ": " << ans << "\n";
        r++;
    }

    cout<<ans<<"\n";
    
}

void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    int head=-1, tail=0;
    unordered_map<int, int> mp;
    ll cnt=0;
    while(tail<n){
        // move head as far as possible
        /** Prb with this condition:
         * agar ==k hai, toh head++ tab hi hoga jab new element na ho
         * <k par hamesha kar do head++
        */
        while(mp.size()<=k && head<n-1){
            head++;
            mp[a[head]]++;
        }
        // remove last element
        if(mp.size()>k){
            mp[a[head]]--;
            if(mp[a[head]]==0) mp.erase(a[head]);
            head--;
        }
    
        // cout << "size: " << mp.size() << "\n";
        // update ans
        // cout << tail << " " << head << " => ";
        // // print map
        // for(auto x: mp){
        //     cout << x.first << " " << x.second << ", ";
        // }
        // cout << "\n";
        if(tail>head)
            head=tail-1;
        cnt += head-tail+1;
        // move tail
        // if(tail>head){  // if empty subarr
        //     tail++;     // erase/update map?
        //     head=tail-1;
        //     continue;
        // }
        mp[a[tail]]--;
        if(mp[a[tail]]==0) mp.erase(a[tail]);
        tail++;
        
    }
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
    solve();
    }
    return 0;
}