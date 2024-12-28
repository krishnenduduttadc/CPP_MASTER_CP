#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
vector<int> order;
int vis[N];

void dfs(int cur, int par) {
    vis[cur] = 1;
    for (auto x : gr[cur]) {
        if (!vis[x]) {
            dfs(x, cur);
        }
    }
    // I am here because I came back from the subtree
    order.push_back(cur);
    return;
}

int main()
{
    // Hardcoded input
    int n = 6, m = 6; // Number of nodes and edges

    // Hardcoded directed graph edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {3, 4},
        {3, 5},
        {4, 6},
        {5, 6}
    };

    // Build the adjacency list
    for (auto edge : edges) {
        int x = edge.first, y = edge.second;
        gr[x].push_back(y);
    }

    // Perform DFS for topological sort
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0);
    }

    // Reverse the order to get topological order
    reverse(order.begin(), order.end());

    // Print the topological order
    for (auto x : order) cout << x << " ";

    return 0;
}
