#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int v){
        V = v;
        // Array of Linked List
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool bidir = true){
        l[i].push_back(j);
        if(bidir){
            l[j].push_back(i);
        }
    }

    int traverseHelper(int s, bool *visited){
        visited[s] = true;
        int size = 1;

        // Visit the neighbours of s and their neighbours recursively
        for(int nbr : l[s]){
            if(!visited[nbr]){
                size += traverseHelper(nbr, visited);
            }
        }
        return size;
    }

    // DFS - Depth First Search O(V+E) Linear
    int countAstronauts(){
        bool *visited = new bool[V]{0};
        int ans = V * (V - 1) / 2;  // Total number of pairs of astronauts

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                // Find the size of the connected component
                int csize = traverseHelper(i, visited);
                ans -= (csize) * (csize - 1) / 2;  // Subtract the pairs within the same component
            }
        }
        return ans;
    }
};

int count_pairs(int n, vector<pair<int, int>> astronauts){
    // Create graph and add edges based on astronaut pairs
    Graph g(n);
    
    for(auto edge : astronauts){
        g.addEdge(edge.first, edge.second);
    }
    
    return g.countAstronauts();
}

int main() {
    // Hardcoded test case
    int n = 5;  // Number of astronauts
    vector<pair<int, int>> astronauts = {
        {0, 1},  // Astronaut 0 and 1 are in the same space station
        {1, 2},  // Astronaut 1 and 2 are in the same space station
        {3, 4}   // Astronaut 3 and 4 are in the same space station
    };

    // Calculate the number of astronaut pairs that cannot meet
    int result = count_pairs(n, astronauts);

    // Output the result
    cout << "Number of astronaut pairs who can't meet: " << result << endl;

    return 0;
}
