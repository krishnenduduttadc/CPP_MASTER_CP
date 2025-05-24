#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Chinese Remainder Theorem solver
int crt(int a1, int m1, int a2, int m2) {
    int x, y;
    int g = extended_gcd(m1, m2, x, y);
    if ((a2 - a1) % g != 0) return -1; // No solution exists
    int lcm = m1 / g * m2;
    int res = (a1 + (long long)(a2 - a1) / g * x % (m2 / g) * m1) % lcm;
    return (res + lcm) % lcm; // Ensure positive result
}

int main() {
    // Test cases
    int a1, m1, a2, m2, x, y;  // Declare x and y here for reuse

    // Test case 1: x ≡ 2 mod 3, x ≡ 3 mod 5 => x = 8
    a1 = 2; m1 = 3;
    a2 = 3; m2 = 5;
    int result = crt(a1, m1, a2, m2);
    cout << "For x ≡ " << a1 << " mod " << m1 << " and x ≡ " << a2 << " mod " << m2 << ":\n";
    cout << "Solution x = " << result << "\n\n";

    // Test case 2: x ≡ 1 mod 4, x ≡ 3 mod 5 => x = 11
    a1 = 1; m1 = 4;
    a2 = 3; m2 = 5;
    result = crt(a1, m1, a2, m2);
    cout << "For x ≡ " << a1 << " mod " << m1 << " and x ≡ " << a2 << " mod " << m2 << ":\n";
    cout << "Solution x = " << result << "\n\n";

    // Test case 3: No solution (inconsistent)
    a1 = 1; m1 = 2;
    a2 = 2; m2 = 4;
    result = crt(a1, m1, a2, m2);
    cout << "For x ≡ " << a1 << " mod " << m1 << " and x ≡ " << a2 << " mod " << m2 << ":\n";
    if (result == -1) {
        cout << "No solution exists (equations are inconsistent)\n\n";
    } else {
        cout << "Solution x = " << result << "\n\n";
    }

    // Test case 4: x ≡ 0 mod 2, x ≡ 0 mod 3 => x ≡ 0 mod 6
    a1 = 0; m1 = 2;
    a2 = 0; m2 = 3;
    extended_gcd(m1, m2, x, y); // Compute GCD and update x, y
    int lcm = m1 / extended_gcd(m1, m2, x, y) * m2; // Recompute LCM
    result = crt(a1, m1, a2, m2);
    cout << "For x ≡ " << a1 << " mod " << m1 << " and x ≡ " << a2 << " mod " << m2 << ":\n";
    cout << "Solution x ≡ " << result << " mod " << lcm << "\n\n";

    return 0;
}