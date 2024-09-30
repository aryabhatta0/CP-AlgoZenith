// Design a Data Structure with 'add' , 'remove' , and 'top K sum' queries
// Maintaining sum of top K elements

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/* Always check if set is empty or not at appropriate places */
// Intuition: We're adding elements and maintaining topK sum. 
// But remove is the problem, so we need to maintain another set for elements other than topK

struct myDS {
    // broken multiset idea //
    multiset<int> topK, smaller;
    int k;
    ll sum=0;

    myDS(int k){
        this->k = k;
    }

    void add(int x){
        if(topK.size() < k) {
            sum+=x;
            topK.insert(x);
        }
        else {
            if(*topK.begin() > x) smaller.insert(x);
            else {
                sum -= *topK.begin();
                sum += x;

                smaller.insert(*topK.begin());
                topK.erase(topK.begin());
                topK.insert(x);
            }
        }
    }

    void remove(int x){
        if(smaller.find(x)!=smaller.end()) smaller.erase(smaller.find(x));
        else if(topK.find(x)!=topK.end()){
            sum -= x;
            topK.erase(topK.find(x));

            if(!smaller.empty()) {
                sum += *smaller.rbegin();
                topK.insert(*smaller.rbegin());
                smaller.erase(prev(smaller.end()));
            }
        }
    }

    ll sumK(){
        return sum;
    }
};

void solve(){
    int q, k; cin>>q>>k;
    myDS ds(k);
    while(q--){
        int ch; cin>>ch;
        if(ch==1) {
            int x; cin>>x;
            ds.add(x);
        } else if(ch==2) {
            int x; cin>>x;
            ds.remove(x);
        } else {
            char ch; cin>>ch;
            cout << ds.sumK() << "\n";
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}