#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 400;

int n = 5, a[N] = {40, 20, 30, 10, 30}, pref[N], memo[N][N];

int sum(int l, int r) {
    return pref[r] - (l == 0 ? 0 : pref[l - 1]);
}

int dp(int l, int r) {
    if (l == r) return 0;  // Base case: no cost to merge a single element
    int &ans = memo[l][r];
    if (ans != 0) return ans;  // If already computed, return the result

    // Initialize the result with a large number (infinity)
    ans = 1e18;
    for (int i = l; i < r; i++) {
        ans = min(ans, dp(l, i) + dp(i + 1, r) + sum(l, r));
    }

    return ans;
}

int32_t main() {
    // Hardcoded input
    // n = 5;
    // a[] = {40, 20, 30, 10, 30};

    // Initialize prefix sum array
    for (int i = 0; i < n; i++) {
        pref[i] = a[i];
        if (i) pref[i] += pref[i - 1];
    }

    // Output the result
    cout << dp(0, n - 1) << endl;

    return 0;
}
