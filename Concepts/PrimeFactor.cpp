#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;
vector<int> primes;

// Sieve of Eratosthenes to generate all primes ≤ N
void sieve() {
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

// Function to compute prime factors of n
vector<int> prime_factors(int n) {
    vector<int> f;
    for (int p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            f.push_back(p);
            n /= p;
        }
    }
    if (n > 1) f.push_back(n); // n is a prime > sqrt(original n)
    return f;
}

int main() {
    sieve();  // Generate primes once

    // Hardcoded example
    int n = 360;
    vector<int> factors = prime_factors(n);

    cout << "Prime factors of " << n << ": ";
    for (int p : factors) cout << p << " ";
    cout << endl;

    return 0;
}
