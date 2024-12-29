#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

vector<int> travelByCar(int n, int l, vector<vector<int>> edges, vector<vector<int>> queries) {
    vector<vector<int>> dis(n, vector<int>(n, inf)), fuel(n, vector<int>(n, inf));
    int x, y, val;
    
    for (int i = 0; i < edges.size(); i++) {
        x = edges[i][0], y = edges[i][1], val = edges[i][2];
        x--; // Convert to 0-based indexing
        y--;
        dis[x][x] = 0;
        dis[y][y] = 0;
        fuel[x][x] = 0;
        fuel[y][y] = 0;
        dis[x][y] = val;
        dis[y][x] = val;
    }
    
    // Floyd-Warshall to compute the shortest distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dis[j][k] > dis[j][i] + dis[i][k]) {
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }
        }
    }
    
    // Determine fuel costs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dis[i][j] <= l) {
                fuel[i][j] = 1;
            }
        }
    }
    
    // Floyd-Warshall to compute the minimum fuel refills
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (fuel[j][k] > fuel[j][i] + fuel[i][k]) {
                    fuel[j][k] = fuel[j][i] + fuel[i][k];
                }
            }
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        x = queries[i][0], y = queries[i][1];
        x--; // Convert to 0-based indexing
        y--;
        if (fuel[x][y] == inf) {
            ans.push_back(-1);
        } else {
            ans.push_back(fuel[x][y] - 1);
        }
    }
    return ans;
}

int main() {
    // Hardcoded test case
    int n = 4; // Number of cities
    int l = 10; // Maximum distance a car can travel on a full tank
    vector<vector<int>> edges = {
        {1, 2, 5}, // {city1, city2, distance}
        {2, 3, 8},
        {3, 4, 2},
        {4, 1, 7}
    };
    vector<vector<int>> queries = {
        {1, 3}, // {start city, end city}
        {4, 2},
        {1, 4},
        {2, 1}
    };

    // Call the function
    vector<int> result = travelByCar(n, l, edges, queries);

    // Output results
    cout << "Minimum refuels required for each query:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
