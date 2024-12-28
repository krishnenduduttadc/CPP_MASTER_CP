#include<bits/stdc++.h>

using namespace std;

const int N = 1e5, M = 20;

vector<int> gr[N];
int dep[N], Par[N][M];

// O(N*M)
void dfs(int cur, int par) {
    dep[cur] = dep[par] + 1;

    Par[cur][0] = par;
    for (int j = 1; j < M; j++) {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }

    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

// O(M) = logN
int LCA(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = M - 1; j >= 0; j--) {
        if ((diff >> j) & 1) {
            // jth bit of diff is set
            u = Par[u][j];
        }
    }
    // u and v are on the same level
    for (int j = M - 1; j >= 0; j--) {
        if (Par[u][j] != Par[v][j]) {
            u = Par[u][j];
            v = Par[v][j];
        }
    }

    // Par[v][0]
    return Par[u][0];
}

// O(1)
int LengthFromUtoV(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}

int main()
{
    // Hardcoded input
    int n = 12; // Number of nodes

    // Hardcoded edges of the tree
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {3, 7},
        {6, 8},
        {6, 9},
        {8, 10},
        {8, 11},
        {11, 12}
    };

    // Construct the adjacency list
    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // Preprocessing the tree
    dfs(1, 0);

    // Test the function LengthFromUtoV
    cout << "Length between 9 and 12: " << LengthFromUtoV(9, 12) << '\n';
    cout << "Length between 10 and 8: " << LengthFromUtoV(10, 8) << '\n';

    return 0;
}
