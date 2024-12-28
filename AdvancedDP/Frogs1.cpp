#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main() {

    int n = 6; // Hardcoded number of stones
    int h[] = {30, 10, 60, 10, 60, 50}; // Hardcoded heights of stones

    int dp[n];

    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1] - h[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2]
                    + abs(h[i - 2] - h[i]));
    }

    cout << dp[n - 1]; // Output the minimum cost to reach the last stone

    return 0;
}
