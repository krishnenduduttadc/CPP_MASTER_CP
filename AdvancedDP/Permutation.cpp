#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int mod = 1e9 + 7;

int n;
string str;

int32_t main() {
    // Hardcoded input
    n = 5;  // Length of the string
    str = "<><>";  // The string itself

    int dp[n + 1][n + 1], ans = 0;

    memset(dp, 0, sizeof(dp));

    dp[n][0] = 1;

    for (int i = n - 1; i > 0; i--) {

        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] += dp[i + 1][j - 1];
        }

        for (int s = 0; s <= n; s++) {
            int g = (n - i - s);
            if (g < 0) continue;

            if (str[i - 1] == '<') {
                dp[i][s] = dp[i + 1][s + g - 1] -
                           (s == 0 ? 0 : dp[i + 1][s - 1]);
            }
            else {
                dp[i][s] = dp[i + 1][s - 1];
            }
            dp[i][s] %= mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        ans += dp[1][i - 1];
        ans %= mod;
    }

    ans += mod; ans %= mod;

    cout << ans;

    return 0;
}
