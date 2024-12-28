#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5;
int n, k;
int h[N];
int dp[N];

void go(int i) {
    cout << i + 1 << " "; // Print the stone index (1-based)
    for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
        if (dp[i] == dp[i - kk] + abs(h[i] - h[i - kk])) {
            go(i - kk);
            return;
        }
    }
}

int32_t main() {
    // Hardcoded input
    n = 6;   // Number of stones
    k = 3;   // Maximum jump distance
    int heights[] = {30, 10, 60, 10, 60, 50}; // Heights of stones

    for (int i = 0; i < n; i++) {
        h[i] = heights[i];
    }

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
            dp[i] = min(dp[i], dp[i - kk] + abs(h[i] - h[i - kk]));
        }
    }

    cout << "Minimum cost: " << dp[n - 1] << "\n";

    cout << "Path: ";
    go(n - 1);
    cout << "\n";

    return 0;
}
