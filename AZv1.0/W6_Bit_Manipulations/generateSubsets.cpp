// Given a set, generate all the subsets of the set
// Hint: Use bitmasks

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(const vector<int>& set) {
    int n = set.size();

    // The total number of subsets is 2^n
    int totalSubsets = 1 << n;

    /** Each number in the range [0, 2^n) represents a subset */
    for (int i = 0; i < totalSubsets; i++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            // Check if the j-th bit of i is set
            if (i & (1 << j)) {
                subset.push_back(set[j]);
            }
        }

        // Print the subset
        cout << "{ ";
        for (int k = 0; k < subset.size(); k++) {
            cout << subset[k] << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> set = {1, 2, 3};
    generateSubsets(set);
    return 0;
}
