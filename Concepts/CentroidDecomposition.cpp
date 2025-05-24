#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5; // Maximum number of nodes

vector<int> adj[N];    // Adjacency list
int subtree[N];        // Size of subtree rooted at u
bool vis[N];           // Whether node is already a centroid

// Compute subtree sizes
void dfs(int u, int p) {
    subtree[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    }
}

// Find centroid of tree rooted at u
int centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v != p && !vis[v] && subtree[v] > n/2) {
            return centroid(v, u, n);
        }
    }
    return u;
}

// Centroid Decomposition
void decompose(int u, int p) {
    dfs(u, -1); // Compute subtree sizes
    int c = centroid(u, -1, subtree[u]); // Find centroid
    vis[c] = true; // Mark as centroid

    cout << "Centroid found: " << c << endl; // Print centroid

    // Recurse on subtrees
    for (int v : adj[c]) {
        if (!vis[v]) {
            decompose(v, c);
        }
    }
}

int main() {
    // Hardcoded tree structure (n=7)
    int n = 7;
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
    adj[6].push_back(7);
    adj[7].push_back(6);

    // Initialize
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
    }

    // Start decomposition from root (node 1)
    decompose(1, -1);

    return 0;
}