#include <iostream>
#include<vector>
using namespace std;

#define ll long long

//Give us the size of the tree from the node where it is called
int dfs(int u, int parent, vector<pair<int,int> > adj[], ll &ans, int N){

    int currentTreeSize = 1;
    for(auto p : adj[u]){
        int v = p.first;
        int wt = p.second;
        //Skip the parent node (which is acting as nbr)
        if(v==parent){
            continue;
        }
        int childTreeSize = dfs(v, u, adj, ans, N);
        int edgeContribution = 2 * min(childTreeSize, N - childTreeSize) * wt;
        ans += edgeContribution;
        //update the tree size by adding childTree Size
        currentTreeSize += childTreeSize;
    }
    return currentTreeSize;
}

int main() {
	// your code goes here
    int test = 1; // Hardcoded for 1 test case

    int n = 5; // Number of nodes in the tree

    //Graph
    vector<pair<int,int> > adj[100005];

    // Hardcoded graph edges (u, v, w):
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[3].push_back({4, 4});
    adj[4].push_back({3, 4});

    adj[3].push_back({5, 1});
    adj[5].push_back({3, 1});

    // DFS to calculate the answer
    ll ans = 0;
    dfs(1, -1, adj, ans, n);

    cout << "Case #" << test << ": " << ans << endl;

	return 0;
}
