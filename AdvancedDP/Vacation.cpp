#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5;

int a[N][3], dp[N][3];

int32_t main() {

    // Hardcoded input
    int n = 3; // Number of days
    int activities[][3] = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    // Initialize input array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = activities[i][j];
        }
    }

    // Base case: on day 0, the maximum happiness for each activity
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0;
            for (int jj = 0; jj < 3; jj++) {
                if (j != jj) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][jj] + a[i][j]);
                }
            }
        }
    }

    // Get the maximum happiness on the last day
    cout << "Maximum Happiness: " << *max_element(dp[n - 1], dp[n - 1] + 3) << endl;

    return 0;
}
