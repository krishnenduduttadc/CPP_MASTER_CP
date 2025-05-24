#include <iostream>
using namespace std;

const int N = 2e5 + 5;       // Maximum precomputation limit
const int MOD = 1e9 + 7;      // Standard prime modulus

int fact[N], invfact[N];      // Factorial and inverse factorial arrays

// Fast modular exponentiation (a^b mod MOD)
int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = 1LL * fact[i-1] * i % MOD;
        invfact[i] = modpow(fact[i], MOD-2); // Fermat's little theorem
    }
}

// Combination formula C(n, r) mod MOD
int C(int n, int r) {
    if (r > n || r < 0) return 0;
    return 1LL * fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main() {
    // Precompute all factorials up to N-1
    precompute();

    // Hardcoded test cases
    struct TestCase { int n, r; };
    TestCase tests[] = {
        {5, 2},     // C(5,2) = 10
        {10, 3},    // C(10,3) = 120
        {7, 7},     // C(7,7) = 1
        {6, 4},     // C(6,4) = 15
        {100000, 50000}, // Large case
        {5, 6}      // Invalid case (r > n)
    };

    for (const auto& test : tests) {
        int result = C(test.n, test.r);
        cout << "C(" << test.n << ", " << test.r << ") = " << result;
        if (result == 0 && test.r > test.n) {
            cout << " (Invalid combination)";
        }
        cout << "\n";
    }

    return 0;
}