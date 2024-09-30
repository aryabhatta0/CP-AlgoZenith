// https://maang.in/problems/Count-LIS-919?resourceUrl=cs100-cp506-pl3405-rs919
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int len[1001];      // len of LIS ending at i
int cnt[1001];      // cnt of LIS ending at i

void solve() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // we'll  do a iterative dp
    memset(len, 0, sizeof(len));
    memset(cnt, 0, sizeof(cnt));

    int maxLen=0;
    for(int i=0; i<n; i++){
        len[i]=1; 
        cnt[i]=1;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                if(len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } 
                else if(len[i] == len[j] + 1) {
                    cnt[i] = (cnt[i] + cnt[j]) % mod;
                }
            }
        }

        maxLen = max(maxLen, len[i]);
    }

    int countLIS=0;
    for(int i=0; i<n; i++){
        if(len[i] == maxLen){
            countLIS = (countLIS + cnt[i])%mod;
        }
    }

    cout << countLIS << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}