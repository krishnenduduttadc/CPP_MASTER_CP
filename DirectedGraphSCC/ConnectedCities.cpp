#include <bits/stdc++.h>
using namespace std;

bool BFS(int n, unordered_map<int, set<int>>& g) {
    queue<int> q;
    q.push(0);
    unordered_map<int, bool> vis;
    vis[0] = true;
    while (!q.empty()) {
        int P = q.front();
        q.pop();
        for (auto it = g[P].begin(); it != g[P].end(); ++it) {
            if (!vis[*it]) {
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
    return vis.size() == n;
}

bool solve(int n, vector<vector<int>>& roads) {
    unordered_map<int, set<int>> g;
    for (int i = 0; i < roads.size(); i++) { 
        g[roads[i][0]].insert(roads[i][1]);
    }

    bool allvis = BFS(n, g);
    if (!allvis) {
        return false;
    }

    unordered_map<int, set<int>> revg;
    for (auto it = g.begin(); it != g.end(); ++it) {
        int k = it->first;
        for (auto vit = it->second.begin(); vit != it->second.end(); ++vit) {
            revg[*vit].insert(k);
        }
    }

    allvis = BFS(n, revg);
    return allvis;
}

int main() {
    // Hardcoded test case
    int n = 5; // Number of nodes
    vector<vector<int>> roads = {
        {0, 1},
        {1, 2},
        {2, 0},
        {0, 3},
        {3, 4}
    };

    // Check if the graph is strongly connected
    bool result = solve(n, roads);

    // Print result
    if (result) {
        cout << "The graph is strongly connected." << endl;
    } else {
        cout << "The graph is not strongly connected." << endl;
    }

    return 0;
}
