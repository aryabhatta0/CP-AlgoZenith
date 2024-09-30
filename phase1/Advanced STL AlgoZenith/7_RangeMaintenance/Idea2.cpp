#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
#define F first
#define S second

/** 
 u can only apply upper bound only on left (.F) - set

 _bound on pair<int, int> :
 * st.lower_bound({l, 0});
 * st.upper_bound({l, 1e9});
 */

// Hint: Draw the diagram for both "Overlap" on left/right and "Fully within" case to get the idea !!

struct range_maintainance
{
    set<ii> st;
    void fill_range(int l, int r) {   
        // 1. Merge Overlapping Ranges

        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin()) {
            it--;   // iter to range just before l
            if (it->second >= l) {
                l = it->first;
                r = max(r, it->second);
                st.erase(it);
            }
        }

        it = st.upper_bound({r, 1e9});
        if (it != st.begin()) {
            it--;   // iter to range just after r
            if (it->second >= r) {
                r = it->second;
                // l = min(r, it->second);
                l = min(l, it->first);
                st.erase(it);
            }
        }

        // 2. Remove ranges that're "Fully within" [l, r]
        while (1) {
            it = st.lower_bound({l, 0});
            if (it == st.end() || (it->first > r)) break;
            else st.erase(it);
        }

        // Insert the final merged range
        st.insert({l, r});
    }

    void clear_range(int l, int r) {
        // 1. Overlapping Intervals
        // left side
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin()) {
            it--;

            // curr range fully includes [l, r]
            if (it->second >= r) {
                int lo1 = it->first;
                int hi1 = l;

                int lo2 = r;
                int hi2 = it->second;

                st.erase(it);
                st.insert({lo1, hi1});
                st.insert({lo2, hi2});
                return;
            }

            // overlaps partially
            if (it->second >= l) {
                int lo = it->first;
                int hi = l;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        // right side
        it = st.upper_bound({r, 1e9});
        if (it != st.begin()) {
            it--;
            if (it->second >= r) {
                int lo = r;
                int hi = it->second;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        // 2. Remove ranges that're "Fully Inside" [l, r]
        while (1) {
            it = st.lower_bound({l, 0});
            if (it == st.end() || (it->first > r)) break;
            else st.erase(it);
        }
    }

    bool check_point(int x) {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin()) return false;
        it--;
        return it->second >= x; // Check if x is within the found range
    }

    bool check_range_any(int x, int y) {
        auto it = st.upper_bound({x, 1e9});
        if (it != st.end() && it->first <= y) return true;
        
        // Otherwise, check if x is within any range
        return check_point(x);
    }

    bool check_range_all(int x, int y)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin()) return false; // No range covers this
        it--;
        return it->second >= y; // Check if y is also covered within the found range
    }
};


int main() {
    range_maintainance rm;

    // Fill some ranges
    rm.fill_range(1, 5);
    rm.fill_range(10, 20);
    rm.fill_range(22, 30);

    // Print the current ranges
    cout << "After filling ranges [1, 5], [10, 20], [22, 30]:" << endl;
    for (auto range : rm.st) {
        cout << "[" << range.F << ", " << range.S << "] ";
    }
    cout << endl;

    // Check if a point is in any range
    cout << "Check point 3: " << rm.check_point(3) << endl; // Expected: 1 (true)
    cout << "Check point 15: " << rm.check_point(15) << endl; // Expected: 1 (true)
    cout << "Check point 21: " << rm.check_point(21) << endl; // Expected: 0 (false)

    // Check if any part of range [12, 25] overlaps with existing ranges
    cout << "Check any part of range [12, 25]: " << rm.check_range_any(12, 25) << endl; // Expected: 1 (true)

    // Check if entire range [10, 20] is fully covered
    cout << "Check if entire range [10, 20] is fully covered: " << rm.check_range_all(10, 20) << endl; // Expected: 1 (true)

    // Clear a range and check again
    rm.clear_range(11, 15);
    cout << "After clearing range [11, 15]:" << endl;
    for (auto range : rm.st) {
        cout << "[" << range.F << ", " << range.S << "] ";
    }
    cout << endl;

    // Check if points inside and outside of the cleared range are still covered
    cout << "Check point 12: " << rm.check_point(12) << endl; // Expected: 0 (false)
    cout << "Check point 16: " << rm.check_point(16) << endl; // Expected: 1 (true)

    return 0;
}

