#include<bits/stdc++.h>
using namespace std;
#define inf 2e9

int solve(int n, int k, int l1, int r1, int l2, int r2) {
    int ans = inf;
    if (max(l1, l2) <= min(r1, r2)) {
        long long rem = max((long long)0, k - (long long)n * (long long)(min(r1, r2) - max(l1, l2)));
        long long maxPossible = (long long)n * (long long)(abs(l1 - l2) + abs(r1 - r2));
        ans = min(rem, maxPossible) + max((long long)0, rem - maxPossible) * 2;
    } else {
        long long invest = max(l1, l2) - min(r1, r2);
        for (int i = 1; i <= n; i++) {
            long long curans = invest * i;
            long long maxPossible = (long long)(max(r1, r2) - min(l1, l2)) * (long long)i;
            curans += min((long long)k, maxPossible) + max((long long)0, k - maxPossible) * 2;
            ans = min((long long)ans, curans);
        }
    }
    return ans;
}

int main() {
    // Hardcoded input
    int n = 2;   // Number of intervals
    int k = 8;   // Required total overlap
    int l1 = 1, r1 = 5; // First range [l1, r1]
    int l2 = 10, r2 = 15; // Second range [l2, r2]

    // Call the solve function and print the result
    cout << solve(n, k, l1, r1, l2, r2) << endl;

    return 0;
}
