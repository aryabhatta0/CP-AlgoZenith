// https://maang.in/problems/Scrambled-String-909?resourceUrl=cs117-cp540-pl3649-rs909&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// https://leetcode.com/problems/scramble-string/description/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Intuition:
 * Multiple strings => Multiseq DP
 * Partition over k for transition and see if you could scramble subparts by either swap or no swap
 * Try to reduce try to reduce trivial O(n^5) into O(n^4)
 */

// dp[i][j][len] = if you can scramble s1[i...] into s2[j...]
int dp[41][41][41];
string s1, s2;

bool rec(int i, int j, int len){
    // base case
    if(len==1){
        return s1[i]==s2[j];
    }
    // cache check
    if(dp[i][j][len]!=-1) return dp[i][j][len];
    
    // transition
    int &ans = dp[i][j][len];
    for(int k=1; k<len; k++){   // partition at k
        if(rec(i, j, k) && rec(i+k, j+k, len-k)) return ans=true;
        if(rec(i, j+len-k, k) && rec(i+k, j, len-k)) return ans=true;
    }
    // save and return
    return ans=false;
}

void solve(){
    cin>>s1>>s2;
    // return if s2 is a scrambled string of s1
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 0, s1.size()) ? "Yes\n" : "No\n");
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}