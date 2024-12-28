#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

int n;

const int N = 301;

ld memo[N][N][N];

// Recursive dp function
ld dp(int zero, int one, int two, int three) {
    // Base case: If no items left, return 0
    if (one + two + three == 0) return 0;

    // Memoization: Check if the result is already computed
    ld &ans = memo[one][two][three];
    if (ans != -1.00) return ans;

    // Initialize answer with total items n
    ans = n;

    // Process item of type 1 (if available)
    if (one) ans += one * dp(zero + 1, one - 1, two, three);

    // Process item of type 2 (if available)
    if (two) ans += two * dp(zero, one + 1, two - 1, three);

    // Process item of type 3 (if available)
    if (three) ans += three * dp(zero, one, two + 1, three - 1);

    // Average over the total number of remaining items
    ans /= (ld)(n - zero);

    return ans;
}

int32_t main() {
    // Hardcoded input
    n = 5;
    int a[] = {0, 1, 2, 2, 3}; // Hardcoded array of item types

    int cnt[4] = {0}; // To count occurrences of 0, 1, 2, 3
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    // Initialize memoization table
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                memo[i][j][k] = -1.00;
            }
        }
    }

    // Set precision and calculate the result
    cout << setprecision(10) << fixed;
    cout << dp(cnt[0], cnt[1], cnt[2], cnt[3]) << endl;

    return 0;
}
