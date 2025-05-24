#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 1000000;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) ++count;
    }
    cout << "Number of primes up to " << N << ": " << count << endl;
    return 0;
}
