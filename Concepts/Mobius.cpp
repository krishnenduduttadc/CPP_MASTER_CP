#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100;  // Smaller size for test
bool is_prime[N];
int mu[N];

void sieve() {
    for (int i = 2; i < N; i++) is_prime[i] = true;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) is_prime[j] = false;
        }
    }
}

void mobius() {
    for (int i = 1; i < N; i++) mu[i] = 1;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            for (int j = i; j < N; j += i) mu[j] *= -1;
            for (int j = i * i; j < N; j += i * i) mu[j] = 0;
        }
    }
}

int main() {
    sieve();      // Needed for is_prime[]
    mobius();     // Computes Möbius function

    for (int i = 1; i < 20; i++) {
        printf("mu(%d) = %d\n", i, mu[i]);
    }

    return 0;
}
