#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5 + 1, mod = 1e9 + 7;

vector<int> gr[N];
int memo[N][2];

int dp(int cur, int paint, int par) {
    int &ans = memo[cur][paint];

    if (ans != -1) return ans;

    ans = 1;
    for (auto child : gr[cur]) {
        if (child != par) {
            if (paint) {
                ans *= dp(child, 0, cur) + dp(child, 1, cur);
            }
            else {
                ans *= dp(child, 1, cur);
            }
            ans %= mod;
        }
    }

    return ans;
}

int32_t main() {
    // Hardcoded input
    int n = 5;  // Example number of nodes
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};  // Hardcoded edges

    // Initialize graph (adjacency list)
    for (auto edge : edges) {
        int x = edge.first, y = edge.second;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // Initialize memoization table
    memset(memo, -1, sizeof(memo));

    // Compute the result
    cout << (dp(1, 1, 0) + dp(1, 0, 0)) % mod;

    return 0;
}
