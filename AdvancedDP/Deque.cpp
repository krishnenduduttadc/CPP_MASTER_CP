#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3001;

int n = 4;  // Size of the array
int a[N] = {4, 3, 2, 6};  // Hardcoded input array
int memo[N][N];

// dp(i, j) returns the maximum score difference the current player can achieve
// when playing on the subarray a[i..j].
int dp(int i, int j) {
    if (i == j) return a[i];  // Base case: only one element left, take it.
    int &ans = memo[i][j];
    if (ans != -1e18) return ans;  // If already computed, return the stored result.
    
    // Two choices: pick a[i] or pick a[j], and calculate the best possible outcome.
    ans = max(a[i] - dp(i + 1, j), a[j] - dp(i, j - 1));
    
    return ans;
}

int32_t main() {
    // Initialize memoization table with a very negative number to indicate uncomputed states
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            memo[i][j] = -1e18;
        }
    }

    // Output the result: the maximum score difference for the entire array.
    cout << dp(0, n - 1);

    return 0;
}
