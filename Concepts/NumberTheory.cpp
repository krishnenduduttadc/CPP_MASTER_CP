#include <iostream>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute LCM
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    // Hardcoded test cases
    int a1 = 12, b1 = 18;
    int a2 = 20, b2 = 30;
    int a3 = 7,  b3 = 5;

    // Display results
    cout << "GCD of " << a1 << " and " << b1 << " = " << gcd(a1, b1) << endl;
    cout << "LCM of " << a1 << " and " << b1 << " = " << lcm(a1, b1) << endl;
    
    cout << "GCD of " << a2 << " and " << b2 << " = " << gcd(a2, b2) << endl;
    cout << "LCM of " << a2 << " and " << b2 << " = " << lcm(a2, b2) << endl;

    cout << "GCD of " << a3 << " and " << b3 << " = " << gcd(a3, b3) << endl;
    cout << "LCM of " << a3 << " and " << b3 << " = " << lcm(a3, b3) << endl;

    return 0;
}
