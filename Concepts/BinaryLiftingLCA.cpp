#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5; // Maximum number of nodes
const int LOG = 20;     // Log2(N)

vector<int> adj[N];     // Adjacency list
int up[N][LOG];         // Binary lifting table
int depth[N];           // Depth of each node

// DFS to compute up[][] and depth[]
void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

// LCA using binary lifting
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    // Bring u to the same depth as v
    for (int i = LOG-1; i >= 0; --i)
        if (depth[u] - (1 << i) >= depth[v])
            u = up[u][i];
    if (u == v) return u;
    // Now find the LCA
    for (int i = LOG-1; i >= 0; --i)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
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

    // Build the binary lifting table
    dfs(1, 0); // Root is 1 (parent 0)

    // Sample LCA queries
    cout << "LCA(4, 5) = " << lca(4, 5) << endl; // Expected: 2
    cout << "LCA(4, 6) = " << lca(4, 6) << endl; // Expected: 1
    cout << "LCA(5, 6) = " << lca(5, 6) << endl; // Expected: 1
    cout << "LCA(2, 6) = " << lca(2, 6) << endl; // Expected: 1
    cout << "LCA(3, 6) = " << lca(3, 6) << endl; // Expected: 3

    return 0;
}