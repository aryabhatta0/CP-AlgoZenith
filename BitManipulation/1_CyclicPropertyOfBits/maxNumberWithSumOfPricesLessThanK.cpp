// https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    // if num is a cheap number i.e, accumulated price <= k
    bool cheap(ll num, int x, ll k) {
        ll sum = 0;     // accumulated price of num
        ll tot = num+1;   // [0-num] since 0 doesn't really contribute
        for(int i=x; i<=63; i+=x) {    
            ll full = tot / (1LL<<i);   // full grps of size 2^i since x is 1-indexed
            ll left = tot % (1LL<<i);
            ll extra = max(left - (1LL<<(i-1)), 0LL);   // each grp has 2^(i-1) 1s and 0s

            sum += full * (1LL<<(i-1)) + extra;
            if(sum>k) return 0;
        }

        return sum <= k;
    }

    long long findMaximumNumber(long long k, int x) {
        // binary search on number
        ll lo=0, hi=1e15;
        // hi?? hi can be greater than k as well, why?
        ll ans=-1;
        while(lo <= hi) {
            ll mid = (lo+hi)/2;
            if(cheap(mid, x, k)) {
                ans = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        return ans;
    }
};