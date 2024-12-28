#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int Par[N];

void dfs(int cur, int par) {
    Par[cur] = par;
    for (auto x : gr[cur]) {
        if (x != par) {
            // x is child node
            dfs(x, cur);
        }
    }
}

int main()
{
    // Hardcoded input
    int n = 5; // Number of nodes

    // Hardcoded edges of the tree
    vector<pair<int, int>> edges = {
        {10, 2},
        {10, 3},
        {3, 4},
        {3, 6}
    };

    // Construct the adjacency list
    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // Perform DFS to compute parent information
    dfs(10, 0);

    int x = 6; // Node for which we need to print ancestors

    // Print all ancestors of node `x`
    while (x) {
        cout << x << '\n';
        x = Par[x];
    }

    return 0;
}
