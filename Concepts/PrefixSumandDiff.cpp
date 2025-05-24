#include <iostream>
#include <vector>
using namespace std;

// Function to compute prefix sum
vector<int> prefix_sum(vector<int> &a) {
    int n = a.size();
    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        ps[i] = ps[i - 1] + a[i - 1];
    return ps;
}

int main() {
    // Hardcoded input array
    vector<int> a = {3, 1, 4, 1, 5, 9, 2};

    // Compute prefix sum
    vector<int> ps = prefix_sum(a);

    // Print prefix sum array
    cout << "Prefix Sum Array: ";
    for (int i = 0; i < ps.size(); ++i) {
        cout << ps[i] << " ";
    }
    cout << endl;

    // Example query: sum of elements from index 2 to 5 (0-based in original array)
    int l = 2, r = 5;
    cout << "Sum from index " << l << " to " << r << " = "
         << ps[r + 1] - ps[l] << endl;

    return 0;
}
