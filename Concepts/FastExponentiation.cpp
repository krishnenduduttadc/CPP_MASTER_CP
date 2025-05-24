#include <iostream>
using namespace std;

// Modular exponentiation: computes a^b mod m efficiently
int modpow(int a, int b, int m) {
    int res = 1;
    a %= m;  // Ensure base is within [0,m-1]
    while (b) {
        // If current bit is set, multiply with current power of a
        if (b & 1) res = (1LL * res * a) % m;
        // Square the base and move to next bit
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    // Hardcoded test cases
    struct TestCase { int a, b, m; };
    TestCase tests[] = {
        {3, 4, 5},      // 3^4 mod 5 = 81 mod 5 = 1
        {2, 10, 1000},   // 2^10 mod 1000 = 1024 mod 1000 = 24
        {5, 0, 7},       // 5^0 mod 7 = 1
        {123456, 789, 1000000007},  // Large case
        {0, 100, 7},     // 0^100 mod 7 = 0
        {7, -1, 10}      // Invalid case (negative exponent)
    };

    for (const auto& test : tests) {
        if (test.b < 0) {
            cout << test.a << "^" << test.b << " mod " << test.m 
                 << " is undefined (negative exponent)\n";
            continue;
        }
        int result = modpow(test.a, test.b, test.m);
        cout << test.a << "^" << test.b << " mod " << test.m 
             << " = " << result << "\n";
    }

    return 0;
}