#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3001;

ld p[N], memo[N][N];
int n;

ld dp(int i, int h, int t) {
    if (i == n) return 1.00;
    ld &ans = memo[i][h];
    if (ans != -1.00) return ans;
    ans = 0.00;
    if (h) {
        ans += dp(i + 1, h - 1, t) * p[i];
    }
    if (t) {
        ans += dp(i + 1, h, t - 1) * (1.00 - p[i]);
    }
    return ans;
}

int32_t main() {

    // Hardcoded input for testing
    n = 5; // Number of trials
    p[0] = 0.6; // Probability of success for trial 1
    p[1] = 0.7; // Probability of success for trial 2
    p[2] = 0.8; // Probability of success for trial 3
    p[3] = 0.5; // Probability of success for trial 4
    p[4] = 0.9; // Probability of success for trial 5

    // Initialize memoization table with -1.00 (indicating uncalculated states)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            memo[i][j] = -1.00;
        }
    }

    ld ans = 0;
    for (int i = (n / 2 + 1); i <= n; i++) {
        ans += dp(0, i, n - i);
    }

    cout << setprecision(10) << fixed;
    cout << ans;

    return 0;
}
