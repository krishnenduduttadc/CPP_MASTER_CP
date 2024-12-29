#include<bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>> edges){
    vector<vector<int>> v(n+1);
    int x, y;
    for(int i = 0; i < edges.size(); i++) {
        x = edges[i][0], y = edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> dis(n+1, 1e9);
    queue<int> q;
    vector<int> visit(n+1);
    q.push(1);
    dis[1] = 1;
    visit[1] = 1;

    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto itr : v[x]) {
            if(!visit[itr]) {
                visit[itr] = 1;
                q.push(itr);
            }
            if(dis[itr] > dis[x] + 1) {
                dis[itr] = dis[x] + 1;
            }
        }
    }

    if(dis[n] == (int)1e9) {
        return -1;
    }
    return dis[n];
}

int main() {
    // Hardcoded test case
    int n = 6; // Number of nodes (1 to 6)
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {5, 6}
    };

    // Call the messageRoute function
    int result = messageRoute(n, edges);

    // Output the result
    cout << "The shortest route from node 1 to node " << n << " is: " << result << endl;

    return 0;
}
