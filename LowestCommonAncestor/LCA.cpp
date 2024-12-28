#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int dep[N], Par[N];

void dfs(int cur, int par) {
    Par[cur] = par;
    dep[cur] = dep[par] + 1;
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v) {
    if (u == v) return u;

    if (dep[u] < dep[v]) swap(u, v);
    // depth of u is more than depth of v

    int diff = dep[u] - dep[v];

    // depth of both nodes same
    while (diff--) {
        u = Par[u];
    }

    // until they are equal nodes keep climbing
    while (u != v) {
        u = Par[u];
        v = Par[v];
    }

    return u;
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

    // Run DFS from node 1, assuming it's the root
    dfs(1, 0);

    // Test LCA queries
    cout << "LCA of 9 and 12: " << LCA(9, 12) << '\n';
    cout << "LCA of 10 and 8: " << LCA(10, 8) << '\n';
    cout << "LCA of 9 and 11: " << LCA(9, 11) << '\n';

    return 0;
}
