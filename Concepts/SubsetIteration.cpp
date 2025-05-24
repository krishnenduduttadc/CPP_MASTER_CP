#include <iostream>
using namespace std;

int main() {
    int n = 3; // number of elements

    for (int mask = 0; mask < (1 << n); ++mask) {
        cout << "Subset " << mask << ": { ";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << "}\n";
    }

    return 0;
}
