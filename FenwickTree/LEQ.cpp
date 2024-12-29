#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

long long bit[maxn][12];

void update(long long index, long long x, long long val) {
    while (index < maxn) {
        bit[index][x] += val;
        index += index & -index;
    }
}

long long get(long long index, long long x) {
    long long ans = 0;
    while (index > 0) {
        ans += bit[index][x];
        index -= index & -index;
    }
    return ans;
}

long long solve(int n, int k, vector<int> seq) {
    memset(bit, 0, sizeof(bit));
    long long ans = 0, val;
    
    for (int i = 0; i < n; i++) {
        update(seq[i], 1, 1); // Update for subsequence length 1
        for (int j = 2; j <= k + 1; j++) {
            val = get(seq[i] - 1, j - 1); // Get number of subsequences of length j-1
            update(seq[i], j, val); // Update for subsequence length j
        }
    }

    ans = get(maxn - 1, k + 1); // Get the answer for subsequences of length k+1
    return ans;
}

int main() {
    // Example input for testing
    int n = 5; // Length of the sequence
    int k = 3; // Maximum subsequence length
    vector<int> seq = {1, 2, 3, 4, 5}; // The sequence

    // Call solve function
    long long result = solve(n, k, seq);

    // Output the result
    cout << "Number of subsequences of length " << k << ": " << result << endl;

    return 0;
}
