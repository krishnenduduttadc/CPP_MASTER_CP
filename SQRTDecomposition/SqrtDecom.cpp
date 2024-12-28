#include<bits/stdc++.h>

using namespace std;

int main() {
    // Hardcoded input values
    int n = 7; // Size of array
    vector<int> a = {1, 2, 3, 4, 5, 6, 7}; // Array elements
    int m = sqrt(n) + 1;
    vector<int> b(m, 0);

    // Preprocessing
    for (int i = 0; i < n; i++) {
        b[i / m] += a[i];
    }

    // Hardcoded queries
    vector<pair<int, int>> queries = {{0, 3}, {1, 5}, {2, 6}};

    // Processing each query
    for (const auto& query : queries) {
        int l = query.first;
        int r = query.second;
        int ans = 0;

        for (int i = l; i <= r;) {
            if (i % m == 0 && i + m - 1 <= r) {
                // lies completely inside the [l...r]
                ans += b[i / m];
                i += m;
            } else {
                ans += a[i];
                i++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
