#include <iostream>
using namespace std;

// Counts the number of set bits (1s) in an integer
int count_bits(int x) {
    return __builtin_popcount(x);
}

int main() {
    // Hardcoded test cases
    int test_numbers[] = {0, 1, 2, 5, 255, 1023, -1};
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    cout << "Number of set bits (1s) in binary representation:\n";
    for (int i = 0; i < num_tests; ++i) {
        int num = test_numbers[i];
        cout << "count_bits(" << num << ") = " << count_bits(num) << "\n";
    }

    return 0;
}