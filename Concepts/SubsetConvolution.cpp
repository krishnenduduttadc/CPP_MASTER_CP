#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3;
    vector<int> f(1 << n);

    // Initialize f with some values for demonstration
    // For example, f[mask] = number of set bits in mask
    for (int mask = 0; mask < (1 << n); ++mask) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) count++;
        }
        f[mask] = count;
    }

    // Perform Fast Subset Sum (SOS DP)
    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if (mask & (1 << i))
                f[mask] += f[mask ^ (1 << i)];

    // Print results
    for (int mask = 0; mask < (1 << n); ++mask) {
        cout << "f[" << mask << "] = " << f[mask] << endl;
    }

    return 0;
}
