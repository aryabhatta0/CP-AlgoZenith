// Highest Common Factor
// Greatest Common Divisor
// Least Common Multiple

/** PROPERTIES:
 * HCF(a, 0) = a
 * Commutative property: HCF(a, b) = HCF(b, a)
 * Euclid's algorithm:
        HCF(a, b) = HCF(a - b, b)
        GCD(a, b) = GCD(b, a % b)

 * LCM: 
        LCM(a,b) * GCD(a,b) = ∣a×b∣
 */

// Time Complexity: O(log(min(a, b)))

#include <iostream>
#include <algorithm> // Required for __gcd function
using namespace std;

// Function to calculate HCF/GCD
int hcf(int a, int b) {
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}


int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "HCF of " << num1 << " and " << num2 << " is: " << hcf(num1, num2) << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm(num1, num2) << endl;
    return 0;
}
