// https://maang.in/problems/Alice-and-Books-84?resourceUrl=cs117-cp540-pl3642-rs84&returnUrl=/courses/DSA-CP-Revision-117?tab=chapters
// Alice read N books. The i-th book has Ai pages. 
// After every book Alice reads, find the largest integer B such that Alice has read B books that have at least B pages.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/** Intuition:
 * Observe that 'ans' can only inc by 1 at a time
 * Think if 'B' is the (prev) optimal ans, when can 'B+1' be the answer as well ?
 * You'll need to store all the books with pages >= 'B+1', if it's count is > 'B' , 'B+1' is the ans.
 * How will you store such books?
 */
// O(nlogn)
void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int ans=0;
    multiset<int> mst;  // set having books with pages > curr ans
    for(auto it: arr){
        if(it>ans) mst.insert(it);

        // if cnt of books with pages>ans is > ans
        if(mst.size()>ans) {
            ans++;    // this'd work too, ans ek baar mein ek hi se badhega naa
            // ans=mst.size();
            
            // remove books with pages <= ans
            while(!mst.empty() && *mst.begin() <= ans) mst.erase(mst.begin());
            // for(auto it: mst) {
            //     if(it < ans) mst.erase(it);
            // }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

// O(n)
void solve2(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // freq[i] = cnt of books with i pages
    int freq[100001] = {};
    int ans = 0;
    int cnt = 0;    // count of books having pages > ans

    for(auto it: arr){
        freq[it]++;
        if(it>ans) cnt++;
        if(cnt>ans) {
            ans++;
            // remove books with pages <= ans
            // cnt was the num books > ans
            cnt-=freq[ans];
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}