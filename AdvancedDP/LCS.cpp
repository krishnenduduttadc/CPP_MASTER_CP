#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3000;

string s, t, res;
int n, m, memo[N][N];

// Function to compute LCS length
int give_lcs(int i, int j) {
	if (i == n || j == m) return 0;

	int &ans = memo[i][j];

	if (ans != -1) return ans;

	if (s[i] == t[j]) ans = give_lcs(i + 1, j + 1) + 1;
	else ans = max(give_lcs(i + 1, j), give_lcs(i, j + 1));

	return ans;
}

// Function to trace back and reconstruct LCS string
void trace_back(int i, int j) {
	if (i == n || j == m) return;

	if (s[i] == t[j]) {
		res += s[i];
		trace_back(i + 1, j + 1);
	} else {
		if (give_lcs(i + 1, j) == give_lcs(i, j)) trace_back(i + 1, j);
		else trace_back(i, j + 1);
	}
}

int32_t main() {

	// Hardcoded input
	s = "abcde";
	t = "ace";
	n = s.size();
	m = t.size();

	// Initialize memo table with -1
	memset(memo, -1, sizeof(memo));

	// Compute LCS length
	int l = give_lcs(0, 0);

	// Reconstruct LCS string
	trace_back(0, 0);

	// Output the LCS string
	cout << "LCS: " << res << endl;

	return 0;
}
