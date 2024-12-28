#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;

int a[N];

struct query {
    int l, r, ans, id, block;
    bool operator< (query P) const {
        return make_pair(this->block, this->r) < make_pair(P.block, P.r);
    }
} q[N];

int main() {
    // Hardcoded input values
    int n = 10; // Size of the array
    vector<int> array_values = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // Array elements
    int queries_count = 3; // Number of queries
    vector<pair<int, int>> query_ranges = {{1, 5}, {2, 8}, {0, 9}}; // Query ranges

    // Initialize array
    int m = sqrt(n);

    for (int i = 0; i < n; i++) {
        a[i] = array_values[i];
    }

    // Initialize queries
    for (int i = 0; i < queries_count; i++) {
        q[i].l = query_ranges[i].first;
        q[i].r = query_ranges[i].second;
        q[i].id = i;
        q[i].block = q[i].l / m;
    }

    // Sort queries
    sort(q, q + queries_count);

    // Print sorted queries
    for (int i = 0; i < queries_count; i++) {
        cout << q[i].id << " " << q[i].l << " " << q[i].r << '\n';
    }

    return 0;
}
