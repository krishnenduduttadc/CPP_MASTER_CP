#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges) {
    int x, y;
    vector<vector<int>> v(n + 1); // adjacency list to store the graph
    vector<int> visit(n + 1, 0);  // visited array
    
    // Build the adjacency list
    for (int i = 0; i < n - 1; i++) {
        x = edges[i][0], y = edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    // Sort neighbors to maintain a consistent order for traversal
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    // Create a queue for BFS
    queue<int> q;
    q.push(1);  // Start BFS from node 1
    visit[1] = 1;  // Mark node 1 as visited
    
    int idx = 0;  // To track the position in the sequence
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Check if the next node in the BFS order matches the sequence
        while (idx < sequence.size() && find(v[current].begin(), v[current].end(), sequence[idx]) != v[current].end()) {
            int next = sequence[idx];
            if (visit[next] == 0) {
                visit[next] = 1; // Mark the node as visited
                q.push(next);  // Add it to the queue
            }
            idx++;  // Move to the next element in the sequence
        }
    }

    // If all nodes are visited and the sequence is valid, return true
    return idx == n;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    vector<int> sequence = {1, 2, 3, 4, 5};

    if (validBfs(n, sequence, edges)) {
        cout << "The sequence is a valid BFS traversal." << endl;
    } else {
        cout << "The sequence is not a valid BFS traversal." << endl;
    }
    
    return 0;
}
