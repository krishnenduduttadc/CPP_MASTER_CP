#include<bits/stdc++.h>

using namespace std;

struct fenwick {
    vector<int> fn;
    int n;
    fenwick() {}
    fenwick(int n) {
        init(n);
    }
    void init(int _n) {
        n = _n + 10;
        fn.clear(); fn.resize(n, 0);
    }
    void add(int x, int val) {
        x++; // 1 based indexing
        while (x < n) {
            fn[x] += val;
            x += (x & (-x));
        }
    }
    int sum(int x) {
        x++; // 1 based indexing
        int ans = 0;
        while (x) {
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    // Hardcoded input values
    int n = 5;
    pair<int, int> a[] = {{5, 0}, {3, 1}, {2, 2}, {4, 3}, {1, 4}};

    sort(a, a + n);
    fenwick tree(n);
    int inversion_count = 0, b[n];

    for (int i = 0; i < n; i++) {
        int element = a[i].first;
        int index = a[i].second;

        b[index] = tree.sum(index + 1, n - 1);

        inversion_count += b[index];
        tree.add(index, 1);
    }

    cout << inversion_count;

    return 0;
}
