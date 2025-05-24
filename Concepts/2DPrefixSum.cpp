#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Hardcoded input matrix (n x m)
    const int n = 3, m = 4;
    int a[n+1][m+1] = {
        {0, 0, 0, 0, 0},  // Padding for 1-based indexing
        {0, 1, 2, 3, 4},  // Row 1
        {0, 5, 6, 7, 8},  // Row 2
        {0, 9, 10, 11, 12} // Row 3
    };

    // Compute prefix sum matrix (ps)
    int ps[n+1][m+1] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ps[i][j] = a[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    // Print the prefix sum matrix
    cout << "Prefix Sum Matrix:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ps[i][j] << " ";
        }
        cout << "\n";
    }

    // Hardcoded submatrix query (r1, c1) to (r2, c2)
    int r1 = 2, c1 = 2; // Top-left corner (inclusive)
    int r2 = 3, c2 = 3; // Bottom-right corner (inclusive)

    // Compute submatrix sum using prefix sums
    int sum = ps[r2][c2] - ps[r1-1][c2] - ps[r2][c1-1] + ps[r1-1][c1-1];

    // Output the result
    cout << "\nSum of submatrix from (" << r1 << "," << c1 << ") to (" << r2 << "," << c2 << "): ";
    cout << sum << "\n";

    return 0;
}