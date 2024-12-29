#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    // Initialize distance array with high values
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // Iterate up to k+1 times to account for at most k stops
    for (int i = 0; i <= k; i++) {
        // Temporary array to store updated distances
        vector<int> tmp(dist);
        
        // Iterate over all flights
        for (auto flight : flights) {
            if (dist[flight[0]] != INT_MAX) {
                // Relax the edge if we can update the distance
                tmp[flight[1]] = min(tmp[flight[1]], dist[flight[0]] + flight[2]);
            }
        }
        
        // Update the dist array with new values
        dist = tmp;
    }
    
    // Return the minimum cost to reach destination, or -1 if not possible
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n = 4; // Number of cities
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}};
    int src = 0, dst = 3, k = 1;
    
    int result = findCheapestPrice(n, flights, src, dst, k);
    
    if (result != -1) {
        cout << "Cheapest price: " << result << endl;
    } else {
        cout << "No valid path within " << k << " stops" << endl;
    }

    return 0;
}
