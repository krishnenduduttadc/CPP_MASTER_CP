#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Graph {

    // Adjacency List
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n) {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst() {
        // Init a Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // Visited array
        bool *vis = new bool[V]{0};
        int ans = 0;

        // Start with node 0
        Q.push({0, 0}); // weight, node

        while (!Q.empty()) {
            // Pick the edge with minimum weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (vis[to]) {
                // Discard the edge
                continue;
            }

            // Take the current edge
            ans += weight;
            vis[to] = 1;

            // Add new edges to the queue
            for (auto x : l[to]) {
                if (!vis[x.first]) {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main() {
    // Hardcoded graph data
    int n = 5; // Number of nodes
    int m = 7; // Number of edges

    // Define edges as {node1, node2, weight}
    vector<tuple<int, int, int>> edges = {
        {1, 2, 2},
        {1, 3, 3},
        {1, 4, 6},
        {2, 3, 2},
        {2, 5, 5},
        {3, 5, 3},
        {4, 5, 1}
    };

    Graph g(n);

    // Add edges to the graph
    for (auto edge : edges) {
        int x = std::get<0>(edge);
        int y = std::get<1>(edge);
        int w = std::get<2>(edge);
        g.addEdge(x - 1, y - 1, w);
    }

    // Print the weight of the MST
    cout << "Minimum Spanning Tree weight: " << g.prim_mst() << endl;

    return 0;
}
