#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N], grr[N];
int vis[N], col[N];
vector<int> order;

vector<int> components[N];

// Topological sorting
void dfs1(int cur) {
    vis[cur] = 1;
    for (auto x : gr[cur]) {
        if (!vis[x]) dfs1(x);
    }
    order.push_back(cur);
}

// Assign components in the reversed graph
void dfs2(int cur, int comp) {
    vis[cur] = 1;
    col[cur] = comp;
    components[comp].push_back(cur);
    for (auto x : grr[cur]) {
        if (!vis[x]) dfs2(x, comp);
    }
}

int main()
{
    // Hardcoded input
    int n = 8, m = 10; // Number of nodes and edges

    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 1},
        {2, 4},
        {4, 5},
        {5, 6},
        {6, 4},
        {7, 6},
        {7, 8},
        {8, 7}
    };

    // Build the graph and its reverse
    for (auto edge : edges) {
        int x = edge.first, y = edge.second;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }

    // Step 1: Perform topological sorting
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }

    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis)); // Reset visited array for second DFS

    // Step 2: Find strongly connected components in reversed graph
    int comp = 1;
    for (auto x : order) {
        if (!vis[x]) dfs2(x, comp++);
    }

    // Print the components
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " belongs to Component " << col[i] << '\n';
    }

    cout << "Total strongly connected components are -> " << comp - 1 << '\n';

    return 0;
}
