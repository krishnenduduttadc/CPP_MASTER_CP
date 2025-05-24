#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5; // Maximum number of nodes
int tin[N], tout[N], timer = 0;
int flat_tree[2 * N]; // Euler Tour array
vector<int> adj[N];   // Adjacency list

// DFS to perform Euler Tour
void dfs(int u, int p) {
    tin[u] = timer;
    flat_tree[timer++] = u;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer - 1; // Inclusive end
}

// Segment Tree for range queries (example: range sum)
int seg_tree[4 * N];

void build(int node, int start, int end) {
    if (start == end) {
        seg_tree[node] = flat_tree[start]; // Or any value you want to store
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1]; // Example: sum
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0; // Out of range
    if (l <= start && end <= r) return seg_tree[node]; // Complete overlap
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + 
           query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    // Hardcoded tree structure (n=6)
    int n = 6;
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[3].push_back(6);
    adj[6].push_back(3);

    // Perform Euler Tour starting from root (node 1)
    dfs(1, -1);

    // Print Euler Tour and in/out times
    cout << "Euler Tour: ";
    for (int i = 0; i < timer; ++i) {
        cout << flat_tree[i] << " ";
    }
    cout << "\n\n";

    cout << "Node\tIn\tOut\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << "\t" << tin[i] << "\t" << tout[i] << "\n";
    }
    cout << "\n";

    // Build segment tree on flattened tree
    build(1, 0, timer - 1);

    // Example query: sum of subtree of node 2 (nodes 2,4,5)
    int l = tin[2], r = tout[2];
    int subtree_sum = query(1, 0, timer - 1, l, r);
    cout << "Subtree sum of node 2: " << subtree_sum << "\n";

    return 0;
}