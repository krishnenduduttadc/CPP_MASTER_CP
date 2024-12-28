#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main() {

    int n = 3, m = 3; // Hardcoded grid dimensions
    string s[3] = {
        "...",  // First row: no obstacles
        ".#.",  // Second row: obstacle at the center
        "..."   // Third row: no obstacles
    };

    int dp[n][m];
    int mod = 1e9 + 7; // Modulo for large numbers

    // Initialize the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1; // Starting point has 1 way to be reached
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1]; // First row, can only come from the left
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j]; // First column, can only come from above
            }
            else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; // Total ways from left and above
                dp[i][j] %= mod; // Take modulo to avoid overflow
            }

            if (s[i][j] == '#') {
                dp[i][j] = 0; // Block the cell if there's an obstacle
            }
        }
    }

    cout << dp[n - 1][m - 1]; // Output the number of ways to reach bottom-right corner
    return 0;
}
