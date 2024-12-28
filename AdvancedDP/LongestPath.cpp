#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int memo[N];

// Function to calculate the longest path from a given node
int dp(int cur) {
	int &ans = memo[cur];
	if (ans != -1) return ans; // Return cached result if already computed
	ans = 0;
	for (auto x : gr[cur]) {
		ans = max(ans, dp(x) + 1); // Longest path by going through the current neighbor
	}
	return ans;
}

int32_t main() {

	// Hardcoded input
	int n = 6, m = 6; // Example: 6 nodes, 6 edges
	vector<pair<int, int>> edges = {
		{1, 2},
		{2, 3},
		{3, 4},
		{4, 5},
		{5, 6},
		{1, 3}
	};

	// Build the graph
	for (auto edge : edges) {
		int x = edge.F, y = edge.S;
		gr[x].push_back(y);
	}

	// Initialize memoization table
	memset(memo, -1, sizeof(memo));

	// Calculate the longest path
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp(i));
	}

	// Output the result
	cout << "Longest Path Length: " << ans << endl;

	return 0;
}
