#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 100;

int v[N], w[N], W, n, memo[N][100001];

// Function to calculate the maximum value
int knapsack(int index, int weight) {
	if (index >= n) return 0;

	// Memoization
	int &ans = memo[index][weight];
	if (ans != -1) return ans;

	// Do not take the item
	ans = knapsack(index + 1, weight);
	// Take the item at the current index
	if (w[index] + weight <= W) {
		ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));
	}
	return ans;
}

int32_t main() {

	// Hardcoded input
	n = 4; // Number of items
	W = 7; // Maximum weight the knapsack can carry

	// Weights and values of items
	int weights[] = {1, 3, 4, 5};
	int values[] = {1, 4, 5, 7};

	// Copy weights and values into arrays
	for (int i = 0; i < n; i++) {
		w[i] = weights[i];
		v[i] = values[i];
	}

	// Initialize memoization array
	memset(memo, -1, sizeof(memo));

	// Output the maximum value
	cout << "Maximum Value: " << knapsack(0, 0) << endl;

	return 0;
}
