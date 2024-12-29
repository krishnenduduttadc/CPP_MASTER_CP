#include <bits/stdc++.h>
using namespace std;

vector<set<int>> v;
vector<int> path;
#define inf 1e9

int dijkstra(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dis(n + 1, inf);
    q.push({0, 1});
    dis[1] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int x = p.second, val = p.first;
        if (x == n) {
            break;
        }
        for (auto itr : v[x]) {
            if (dis[itr] > val + 1) {
                dis[itr] = val + 1;
                q.push({dis[itr], itr});
                path[itr] = x;
            }
        }
    }
    return dis[n] == inf ? -1 : dis[n];
}

vector<int> solve(int n, int m, vector<vector<int>> edge) {
    v = vector<set<int>>(n + 1);
    path = vector<int>(n + 1);
    for (int i = 0; i < m; i++) {
        int x = edge[i][0], y = edge[i][1];
        v[x].insert(y);
    }
    vector<int> ans(m, -1);
    vector<int> tour;
    int value = dijkstra(n);
    set<pair<int, int>> pathedge;
    if (value != -1) {
        int x = n;
        while (x != 1) {
            tour.push_back(x);
            x = path[x];
        }
        tour.push_back(1);
        reverse(tour.begin(), tour.end());
        for (int i = 1; i < tour.size(); i++) {
            pathedge.insert({tour[i - 1], tour[i]});
        }

        for (int i = 0; i < m; i++) {
            int x = edge[i][0], y = edge[i][1];
            v[x].erase(y);
            if (pathedge.find({x, y}) == pathedge.end()) {
                ans[i] = value;
            } else {
                ans[i] = dijkstra(n);
            }
            v[x].insert(y);
        }
    }
    return ans;
}

int main() {
    // Hardcoded test case
    int n = 4; // Number of nodes
    int m = 5; // Number of edges
    vector<vector<int>> edges = {
        {1, 2}, // Edge from node 1 to node 2
        {2, 3}, // Edge from node 2 to node 3
        {3, 4}, // Edge from node 3 to node 4
        {1, 3}, // Edge from node 1 to node 3
        {2, 4}  // Edge from node 2 to node 4
    };

    // Call the function
    vector<int> result = solve(n, m, edges);

    // Output the results
    cout << "Shortest path lengths after removing each edge:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Edge " << edges[i][0] << " -> " << edges[i][1] << ": " << result[i] << endl;
    }

    return 0;
}
