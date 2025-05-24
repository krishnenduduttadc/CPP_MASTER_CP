#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
// Returns gcd(a,b) and finds x,y such that ax + by = gcd(a,b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    // Hardcoded test cases
    struct TestCase { int a, b; };
    TestCase tests[] = {
        {35, 15},  // gcd = 5
        {30, 20},  // gcd = 10
        {17, 5},    // gcd = 1 (coprime)
        {84, 18},   // gcd = 6
        {0, 5}      // Edge case
    };

    for (const auto& test : tests) {
        int x, y;
        int gcd = extended_gcd(test.a, test.b, x, y);
        
        cout << "For a = " << test.a << ", b = " << test.b << ":\n";
        cout << "GCD = " << gcd << "\n";
        cout << "Coefficients x = " << x << ", y = " << y << "\n";
        cout << "Verification: " << test.a << "*" << x << " + " 
             << test.b << "*" << y << " = " << (test.a*x + test.b*y) << "\n\n";
    }

    return 0;
}