#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par) {
    vis[cur] = 1;
    for (auto x : gr[cur]) {
        if (!vis[x]) {
            dfs(x, cur);
        }
        else if (x != par) {
            cycle = true;
        }
    }
}

int main()
{
    // Hardcoded input
    int n = 5; // Number of nodes
    int m = 5; // Number of edges

    // Hardcoded edges of the graph
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5}
    };

    // Construct the adjacency list
    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // Perform DFS for cycle detection
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    // Output the result
    if (cycle) {
        cout << "Yes cycle found\n";
    }
    else {
        cout << "Not found\n";
    }

    return 0;
}
