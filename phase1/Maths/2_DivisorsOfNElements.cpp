#include <bits/stdc++.h>
using namespace std;

/** Finding Divisors of n elements
 * HINT: Precomputation is the key in such cases.
 * Like doing something for multiple elements
*/

const int MAXN = 100100;
vector<int> ans[MAXN];

// Precompute divisors up to 1000
void Divisors()
{
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = i; j <= 1000; j += i)
        {
            ans[j].push_back(i);
        }
    }
}


// Function to find divisors of elements using precomputed values
vector<int> findDivisorsOfElements(const vector<int> &elements)
{
    vector<int> result;

    for (int num : elements)
    {
        // Append precomputed divisors
        result.insert(result.end(), ans[num].begin(), ans[num].end());
    }

    return result;
}
