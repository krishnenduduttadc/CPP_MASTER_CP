#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// DSU Data Structure
// Path Compression + Union By Rank

class DSU {
    int *parent;
    int *rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        
        // Initialize parent to -1, and rank to 1
        for(int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find Function
    int find(int i) {
        if(parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);  // Path Compression
    }

    // Unite (Union) 
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2) {
            // Union by rank
            if(rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }

    int kruskal_mst() {
        // Sort all the edges based on weight
        sort(edgelist.begin(), edgelist.end());

        // Initialize DSU
        DSU s(V);

        int ans = 0;
        for(auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Include edge in MST if it doesn't form a cycle
            if(s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {

    // Hardcoded input for a graph with 4 nodes and 6 edges
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    // Output the weight of the Minimum Spanning Tree (MST)
    cout << "Weight of the Minimum Spanning Tree: " << g.kruskal_mst() << endl;

    return 0;
}
