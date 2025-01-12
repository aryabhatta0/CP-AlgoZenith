#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Sieve of Eratosthenes: 
/**
 * Idea: Starting from i=2, mark all multiples of i non-prime
 * Assumption: All multiples of i that are less than i^2 have already been marked by smaller prime numbers (since they'll have a divisor n/i, less than i)
 * That's why iterate from [2, sqrt(n)]     : for(i=2; i*i <= n; i++)
*/
int n = 100100;
vector<bool> isPrime(n+1, true);

// To find all prime numbers up to N
// T.C: almost O(N)
void sieve(int n) {
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2; i*i <= n; i++) {
        if(!isPrime[i]) {
            // mark all of its multiple false
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = false; 
            }           
        }
    }
}

// Precompute divisors of all numbers upto N
// T.C: O(NlogN)
vector<vector<int>> divisors(n + 1);
void precomputeDivisors(int n) {
    for(int i=2; i<=n; i++) {
        // loop over all multiples
        for(int j=i; j<=n; j+=i) {
            divisors[j].push_back(i);
        }
    }
}