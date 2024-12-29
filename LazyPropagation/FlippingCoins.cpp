#include<bits/stdc++.h>
using namespace std;

vector<int> seg, lazy;

// Update range function
void update(int v, int l, int r, int x, int y) {
    // Apply pending lazy updates
    if (lazy[v]) {
        seg[v] = (r - l + 1) - seg[v];  // Toggle values
        if (l != r) {
            lazy[2 * v] ^= 1;     // Mark left child as lazy
            lazy[2 * v + 1] ^= 1; // Mark right child as lazy
        }
        lazy[v] = 0; // Clear lazy value for current node
    }
    if (y < x) {
        return;
    }
    if (x <= l && y >= r) {
        seg[v] = (r - l + 1) - seg[v];  // Toggle values
        if (l != r) {
            lazy[2 * v] ^= 1;     // Mark left child as lazy
            lazy[2 * v + 1] ^= 1; // Mark right child as lazy
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * v, l, mid, x, min(mid, y));
    update(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

// Query range function
int range(int v, int l, int r, int x, int y) {
    if (y < x) {
        return 0;
    }
    if (lazy[v]) {
        seg[v] = (r - l + 1) - seg[v];  // Apply lazy toggle
        if (l != r) {
            lazy[2 * v] ^= 1;
            lazy[2 * v + 1] ^= 1;
        }
        lazy[v] = 0; // Clear lazy value for current node
    }
    if (x <= l && y >= r) {
        return seg[v];
    }
    int mid = (l + r) / 2;
    return range(2 * v, l, mid, x, min(y, mid)) + range(2 * v + 1, mid + 1, r, max(mid + 1, x), y);
}

// Solve function
vector<int> solve(int n, int q, vector<vector<int>> query) {
    seg = lazy = vector<int>(4 * n + 1); // Initialize segment tree and lazy array
    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int type = query[i][0], x = query[i][1], y = query[i][2];
        if (type == 0) { // Update range
            update(1, 0, n - 1, x, y);
        } else { // Query range
            ans.push_back(range(1, 0, n - 1, x, y));
        }
    }
    return ans;
}

int main() {
    // Hardcoded input
    int n = 5, q = 4;
    vector<vector<int>> query = {
        {0, 1, 3}, // Toggle range [1, 3]
        {1, 2, 4}, // Query range [2, 4]
        {0, 0, 4}, // Toggle range [0, 4]
        {1, 1, 3}  // Query range [1, 3]
    };

    // Solve the problem
    vector<int> result = solve(n, q, query);

    // Print the results of the queries
    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}
