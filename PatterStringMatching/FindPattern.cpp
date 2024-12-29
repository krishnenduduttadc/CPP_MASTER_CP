#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

long long p = 29, mod = 1e9 + 7, power[maxn];

int findPattern(string word, string pattern) {
    power[0] = 1;
    for (int i = 1; i < maxn; i++) {
        power[i] = (power[i - 1] * p) % mod;
    }
    
    int n = word.size(), m = pattern.size();
    vector<long long> hash(n + 1);
    
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + ((word[i] - 'a') * power[i]) % mod) % mod;
    }
    
    long long hash_val = 0;
    int ans = 0;
    
    // Compute hash for the pattern
    for (int i = 0; i < m; i++) {
        hash_val = (hash_val + ((pattern[i] - 'a') * power[i]) % mod) % mod;
    }

    // Check for matching hashes in the word
    for (int i = m; i <= n; i++) {
        long long val = (hash[i] - hash[i - m] + mod) % mod;
        long long new_hash = (hash_val * power[i - m]) % mod;
        if (val == new_hash) {
            ans++;
        }
    }

    return ans;
}

int main() {
    // Example Input: word and pattern
    string word = "ababcababc", pattern = "ab";
    
    // Call the function to find the pattern occurrences
    int result = findPattern(word, pattern);
    
    // Output the result
    cout << "Pattern occurrences: " << result << endl;
    
    return 0;
}
