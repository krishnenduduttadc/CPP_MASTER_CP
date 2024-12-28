#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 101;

int v[N], w[N], W, n, mW[N][100001], dp[N][100001];

int32_t main() {

	// Hardcoded input
	n = 4; // Number of items
	W = 7; // Maximum weight the knapsack can carry

	// Weights and values of items
	int weights[] = {2, 1, 3, 2};
	int values[] = {3, 2, 4, 2};

	for (int i = 1; i <= n; i++) {
		w[i] = weights[i - 1];
		v[i] = values[i - 1];
	}

	// Initialize mW array
	for (int i = 0; i <= n; i++) {
		for (int val = 0; val < 100001; val++) {
			mW[i][val] = 1e13;
		}
	}

	// Base cases
	dp[0][0] = 1;
	mW[0][0] = 0;

	// DP transitions
	for (int i = 1; i <= n; i++) {
		for (int val = 0; val < 100001; val++) {
			// Not taking the current item
			if (dp[i - 1][val]) {
				dp[i][val] = 1;
				mW[i][val] = min(mW[i][val], mW[i - 1][val]);
			}
			// Taking the current item
			if (val - v[i] >= 0 && dp[i - 1][val - v[i]] &&
			    mW[i - 1][val - v[i]] + w[i] <= W) {
				dp[i][val] = 1;
				mW[i][val] = min(mW[i][val], mW[i - 1][val - v[i]] + w[i]);
			}
		}
	}

	// Find the maximum value we can achieve within the weight limit
	int ans = 0;
	for (int val = 0; val < 100001; val++) {
		if (dp[n][val]) ans = val;
	}

	cout << "Maximum Value: " << ans << endl;

	return 0;
}
