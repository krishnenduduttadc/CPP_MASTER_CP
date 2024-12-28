#include<bits/stdc++.h>

using namespace std;

// Summation segment tree
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // Leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // Left subtree is (start, mid)
        build(start, mid, 2 * node + 1, v);

        // Right subtree is (mid+1, ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int ending, int l, int r, int node) {
        // Non-overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // Complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // Partial overlap
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value) {
        // Base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // Left subtree
            update(start, mid, 2 * node + 1, index, value);
        } else {
            // Right subtree
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

int32_t main() {
    // Hardcoded input vector
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    segmenttree tree;
    tree.init(v.size());
    tree.build(v);

    cout << tree.query(0, 4) << '\n'; // Query the sum from index 0 to 4

    tree.update(4, 10); // Update the value at index 4 to 10

    cout << tree.query(2, 6) << '\n'; // Query the sum from index 2 to 6

    tree.update(2, 20); // Update the value at index 2 to 20

    cout << tree.query(0, 4) << '\n'; // Query the sum from index 0 to 4

    return 0;
}
