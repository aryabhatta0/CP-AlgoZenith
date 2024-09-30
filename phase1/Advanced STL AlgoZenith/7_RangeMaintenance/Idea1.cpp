#include <bits/stdc++.h>
using namespace std;

/** Concept:
 * Passes through Y:   Ranges with Li<=Y && Ri>=Y   (2 constraint)
 * Don't pass through Y:    Ranges with Ri<Y || Li>Y    (1 constraint - each range has to satisfy just 1 of the constraints)

 * Handling 2 inequalities(constraints) at once is difficult!
 */

int count_ranges( vector<int> &starts, vector<int>& ends, int Y) {
    // Find the number of ranges that start after Y
    // # ranges with Li > Y
    // int start_count = starts.size() - (upper_bound(starts.begin(), starts.end(), Y) - starts.begin());
    int start_count = starts.end() - upper_bound(starts.begin(), starts.end(), Y);

    // Find the number of ranges that ends before Y
    // # ranges with Ri < Y
    int end_count = (lower_bound(ends.begin(), ends.end(), Y) - ends.begin());

    // The number of ranges passing through Y is the overlap
    return (starts.size() - (start_count + end_count));
}

int main() {
    vector<pair<int, int>> ranges = {{1, 5}, {3, 7}, {6, 9}, {8, 11}};
    vector<int> queries = {3, 6, 8};

    vector<int> starts, ends;
    for (const auto& range : ranges) {
        starts.push_back(range.first);
        ends.push_back(range.second);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for (int Y : queries) {
        cout << count_ranges(starts, ends, Y) << endl;
    }
}
