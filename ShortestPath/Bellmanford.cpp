#include<bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int> > edges) {

    // create a vector for distances
    vector<int> dist(V + 1, INT_MAX);
    dist[src] = 0;

    // relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative weight cycle
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle found!" << endl;
            exit(0);
        }
    }
    return dist;
}

int main() {
    // Hardcoded input for 5 nodes and 8 edges
    int n = 5, m = 8;

    // Edge list (u, v, weight)
    vector<vector<int>> edges = {
        {1, 2, -1},
        {1, 3, 4},
        {2, 3, 3},
        {2, 4, 2},
        {2, 5, 2},
        {4, 2, 1},
        {5, 4, -3},
        {3, 5, 5}
    };

    // Apply Bellman-Ford algorithm starting from node 1
    vector<int> distances = bellman_ford(n, 1, edges);

    // Output distances from source node (1)
    for (int i = 1; i <= n; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << " is unreachable" << endl;
        } else {
            cout << "Node " << i << " is at distance " << distances[i] << endl;
        }
    }

    return 0;
}
