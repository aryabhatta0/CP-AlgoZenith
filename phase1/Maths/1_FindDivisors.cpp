#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Func to precompute divisors of all numbers upto N
// Idea: Loop over all multiples upto N
// Time Complexity: O(nlogn)
vector<vector<int>> precomputeDivisors(int N) {
    vector<vector<int>> divisors(N + 1);
    for (int i = 1; i <= N; ++i) {
        // Loop over all multiples of i
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}


/** CONCEPT: 
 * Factors exists in pairs with one of them lesser than sqrt(n)
 * For a number n, if d is a divisor, then n/d is also a divisor.
*/

// Function to find divisors of a number n using sqrt(n)
vector<int> findDivisors(int n) {
    vector<int> divisors;

    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); ++i) {
        // If i is a divisor of n
        if (n % i == 0) {
            // If the divisors are the same, only add it once (for perfect squares)
            if (n / i == i) {
                divisors.push_back(i);
            } else {
                // Add both divisors
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}

int main() {
    // Example: Finding divisors of 24
    int number = 24;

    cout << "Divisors of " << number << " are: ";
    
    // Call the function to find divisors
    vector<int> divisors = findDivisors(number);

    // Display the divisors
    for (int divisor : divisors) {
        cout << divisor << " ";
    }

    return 0;
}
