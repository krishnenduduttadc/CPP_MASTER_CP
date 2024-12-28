#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;

int a[N], cnt[N * 10], distinct;

struct query {
    int l, r, id, block, ans;
    bool operator<(query P) const {
        return make_pair(this->block, r) < make_pair(P.block, P.r);
    }
} q[N];

bool comp(query a, query b) {
    return a.id < b.id;
}

void add(int val) {
    cnt[val]++;
    if (cnt[val] == 1) distinct++;
}

void remove(int val) {
    cnt[val]--;
    if (cnt[val] == 0) distinct--;
}

int main()
{
    // Hardcoded input
    int n = 9;  // Size of the array
    int queries = 3; // Number of queries

    int m = sqrt(n);

    // Hardcoded array
    int tempArray[] = {1, 2, 1, 3, 4, 2, 3, 5, 6};
    for (int i = 0; i < n; i++) {
        a[i] = tempArray[i];
    }

    // Hardcoded queries
    vector<pair<int, int>> tempQueries = {
        {1, 5}, // Query 1
        {2, 8}, // Query 2
        {4, 9}  // Query 3
    };

    for (int i = 0; i < queries; i++) {
        q[i].l = tempQueries[i].first - 1; // Convert 1-based to 0-based
        q[i].r = tempQueries[i].second - 1; // Convert 1-based to 0-based
        q[i].id = i;
        q[i].block = q[i].l / m;
    }

    sort(q, q + queries);

    int x = 0, y = 0;

    for (int i = 0; i < queries; i++) {
        while (y <= q[i].r) {
            add(a[y]);
            y++;
        }

        while (y > q[i].r + 1) {
            y--;
            remove(a[y]);
        }

        while (x < q[i].l) {
            remove(a[x]);
            x++;
        }

        while (x > q[i].l) {
            x--;
            add(a[x]);
        }

        q[i].ans = distinct;
    }

    sort(q, q + queries, comp);

    for (int i = 0; i < queries; i++) {
        cout << q[i].ans << '\n';
    }

    return 0;
}
