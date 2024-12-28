#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main() {

    // Hardcoded values for n and k
    int n = 5, k = 10;  // For example, let's take n = 5 and k = 10
    int a[] = {0, 2, 4, 6, 2, 8};  // Array values, the 0th index is unused.

    int mod = 1e9 + 7;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= k; j++) {
            dp[i - 1][j] += dp[i - 1][j - 1];
        }

        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] > 0) dp[i][j] -= dp[i - 1][j - a[i] - 1];
            dp[i][j] = ((dp[i][j] % mod) + mod) % mod;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
