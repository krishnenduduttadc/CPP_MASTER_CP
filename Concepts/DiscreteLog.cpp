#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

// Solves a^x ≡ b (mod m) for x using Baby-step Giant-step algorithm
int discrete_log(int a, int b, int m) {
    a %= m;
    b %= m;

    // Handle special cases
    if (b == 1) return 0;
    if (a == 0) {
        if (b == 0) return 1; // 0^1 ≡ 0
        return -1; // 0^x ≡ b (b≠0) has no solution
    }

    int n = sqrt(m) + 1;
    unordered_map<int, int> vals;

    // Baby-step: store all a^q * b mod m for q = 0..n-1
    int cur = b;
    for (int q = 0; q < n; ++q) {
        vals[cur] = q;
        cur = (1LL * cur * a) % m;
    }

    // Precompute a^n mod m
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (1LL * an * a) % m;

    // Giant-step: check for matches with baby-steps
    cur = an;
    for (int p = 1; p <= n; ++p) {
        if (vals.count(cur))
            return p * n - vals[cur];
        cur = (1LL * cur * an) % m;
    }

    return -1; // No solution found
}

int main() {
    // Hardcoded test cases
    struct TestCase { int a, b, m; };
    TestCase tests[] = {
        {2, 1, 5},       // 2^x ≡ 1 mod 5 → x=0 (since 2^0=1)
        {3, 4, 7},       // 3^x ≡ 4 mod 7 → x=4 (3^4=81≡4 mod7)
        {5, 3, 11},      // 5^x ≡ 3 mod11 → x=2 (5^2=25≡3 mod11)
        {2, 3, 10},      // No solution
        {123456, 789, 1000003} // Large case
    };

    for (const auto& test : tests) {
        int x = discrete_log(test.a, test.b, test.m);
        if (x == -1) {
            cout << "No solution for " << test.a << "^x ≡ " << test.b 
                 << " (mod " << test.m << ")\n";
        } else {
            cout << test.a << "^" << x << " ≡ " << test.b 
                 << " (mod " << test.m << ")\n";
        }
    }

    return 0;
}