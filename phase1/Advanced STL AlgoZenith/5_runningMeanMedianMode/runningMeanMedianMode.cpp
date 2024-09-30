#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000007;

ll binPow(ll base, ll exp, ll mod) {
    if(exp==0) return 1;
    if(exp%2 != 0) {
        return base * binPow(base, exp-1, mod) % mod;
    } else {
        ll temp = binPow(base, exp/2, mod);
        return temp * temp % mod;
    }
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll modFraction(ll P, ll Q, ll mod) {
    ll g = gcd(P, Q);
    P /= g;
    Q /= g;
    ll Qinv = binPow(Q, mod - 2, mod);
    return (P * Qinv) % mod;
}

struct dashboard {
    // mean
    ll sum = 0;
    int cnt = 0;
    // median
    multiset<int> mst1, mst2;   
    // mode
    map<int, int> mp;           // freq
    set<pair<int, int>> freq;   // {freq, -elem}

    dashboard() {
        sum = 0; cnt = 0;
        mst1.clear(); mst2.clear();
        mp.clear(); freq.clear();
    }

    // solution used a 'while' here, but this'd also work
    void balance_medSet(){
        if (mst1.size() > mst2.size() + 1) {
            mst2.insert(*mst1.rbegin());
            mst1.erase(prev(mst1.end()));
        } else if (mst2.size() > mst1.size()) {
            mst1.insert(*mst2.begin());
            mst2.erase(mst2.begin());
        }
    }

    void insert(int x) {
        // mean
        (sum += x) %= mod; 
        cnt++;

        // median
        if (mst1.empty() || x <= *mst1.rbegin()) {
            mst1.insert(x);
        } else {
            mst2.insert(x);
        }
        balance_medSet();

        // mode
        if (mp[x] > 0) freq.erase({mp[x], -x});
        mp[x]++;
        freq.insert({mp[x], -x});
    }

    void remove(int x) {
        // if(mp.find(x) == mp.end() || mp[x] == 0) return;  // Check if x exists

        // mean
        sum -= x; 
        if(sum < 0) sum = (sum + mod) % mod;
        cnt--;

        // median
        if (mst1.find(x) != mst1.end()) {
            mst1.erase(mst1.find(x));
        } else if (mst2.find(x) != mst2.end()) {
            mst2.erase(mst2.find(x));
        }
        balance_medSet();

        // mode
        freq.erase({mp[x], -x});
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
        else  freq.insert({mp[x], -x}); 
    }

    ll getMean() {
        if (cnt == 0) return -1;  // Check for division by zero
        return modFraction(sum, cnt, mod);
    }

    int getMode() {
        if(freq.empty()) return -1;  // No mode if freq is empty
        return -freq.rbegin()->second; 
    }

    ll getMedian() {
        if (cnt == 0) return -1;

        if (cnt % 2 != 0) {
            return *mst1.rbegin();
        } else {
            ll P = *mst1.rbegin() + *mst2.begin();
            return modFraction(P, 2, mod);
        }
    }
};

void solve(){
    int q;
    cin >> q;
    dashboard mybag;
    while(q--){
        string str; cin >> str;
        int x;
        if(str == "insert") {
            cin >> x; mybag.insert(x);
        } else if(str == "remove") {
            cin >> x; mybag.remove(x);
        } 
        else if(str=="getMean") cout << mybag.getMean() << "\n";
        else if(str=="getMedian") cout << mybag.getMedian() << "\n";
        else if(str=="getMode") cout << mybag.getMode() << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}