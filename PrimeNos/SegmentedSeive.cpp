#include<iostream>
#include<vector>
using namespace std;

#define N 100000

int sieveArr[N+1] = {0};
vector<int> primes;

// Sieve of Eratosthenes (O(NLogLogN))
void sieve(){
    for(long long i=2; i<=N; i++){
        // Mark non-primes as 1
        if(sieveArr[i] == 0){
            primes.push_back(i);
            // Marking all multiples of i (prime) as non-prime
            for(long long j = i*i; j <= N; j += i){
                sieveArr[j] = 1; // Non-prime
            }
        }
    }
}

// Segmented Sieve
int main(){
    // Precompute
    sieve();

    // Hardcoded test cases
    int t = 2; // Number of test cases
    vector<pair<int, int>> testCases = {{10, 20}, {30, 50}};

    for(int test = 0; test < t; test++){
        int m = testCases[test].first;
        int n = testCases[test].second;

        vector<int> segment(n-m+1, 0);

        // Iterate over the primes, mark multiples of
        // prime in segment array as non-prime (1)
        for(auto p : primes){
            // Stop the loop if prime is larger than root n
            if(p*p > n){
                break;
            }

            int start = (m/p) * p;
            
            // Don't start from 0, instead 2 * prime
            if(p >= m && p <= n){
                start = 2 * p;
            }

            for(int j = start; j <= n; j = j + p){
                if(j < m){
                    continue;
                }
                // Non-prime
                segment[j - m] = 1;
            }
        }

        // Loop over the numbers m ... n and print the primes
        for(int i = m; i <= n; i++){
            if(segment[i-m] == 0 && i != 1){
                cout << i << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
