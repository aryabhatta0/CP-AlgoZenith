#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

//////////////////////////// SOLUTION 1 ///////////////////////////////////
/** Intuition:
 - We'll have a sliding window ofcourse
 - and we need a DS that supports add, remove and getMax operations
 - => multiset  O(nlogK)
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    multiset<int> mst;
    for(int i=0; i<nums.size(); i++){
        if(mst.size()<k-1) mst.insert(nums[i]);
        else {
            mst.insert(nums[i]);
            ans.push_back(*mst.rbegin());
            mst.erase(mst.find(nums[i-k+1]));
        }
    }
    return ans;
}

////////////////////////// SOLUTION 2 ///////////////////////////////////
/**  Monotone deque: We maintain a deque with max at front
    1. insert ka fundae yeh hai ke once we see x in window, elements < x seen before x will be of no use
    2. remove ka fundae yeh hai ke the elemets that gets added first, will also be removed first
       so agar x max hoga toh top se remove kar do warna wo hoga hi nahi deque mein
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // monotone deque - we maintain max at front
    deque<int> dq;
    for(int i=0; i<k; i++){
        while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
        dq.push_back(nums[i]);
    }

    vector<int> ans;
    for(int i=0; i+k<nums.size(); i++){
        ans.push_back(dq.front());
        // remove nums[i]
        if(dq.front()==nums[i]) dq.pop_front();

        // insert nums[i+k]
        while(!dq.empty() && dq.back() < nums[i+k]) dq.pop_back();
        dq.push_back(nums[i+k]);
    }
    ans.push_back(dq.front());
    return ans;
}

///////////////////////////////////// SOLUTION 3 //////////////////////////////
/**
 * Monotone deque: We'll maintain a deque with max at front
 * Key Idea: Once we see a element x, all earlier element lesser than x would be of no use in the window
*/
struct ds {
    deque<int> dq;
    ds() { dq.clear(); }

    void insert(int x){
        while(!dq.empty() && dq.back()<x) dq.pop_back();   // won't be of use (max) in further windows
        dq.push_back(x);
    }
    void remove(int x){
        // either x will be max, or it won't be there, or the element added first will get removed first
        if(!dq.empty() && dq.front()==x) dq.pop_front();
    }
    int getMax(){
        return dq.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    ds myds;
    for(int i=0; i<k; i++) myds.insert(nums[i]);

    vector<int> ans;
    ans.push_back(myds.getMax());
    for(int i=0; i+k<nums.size(); i++){
        myds.remove(nums[i]);
        myds.insert(nums[i+k]);
        ans.push_back(myds.getMax());
    }
    return ans;
}



void solve() {
    
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}