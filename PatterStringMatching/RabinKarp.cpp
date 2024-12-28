#include<bits/stdc++.h>

#define int long long int

using namespace std;

const int p = 31, mod = 1e9 + 7;

int poly_hash(string s) {
    int hash = 0;
    int p_power = 1;

    // Compute the hash of the string
    for (int i = 0; i < s.size(); i++) {
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= p;

        hash %= mod;
        p_power %= mod;
    }

    return hash;
}

int powr(int a, int b) {
    // Modular exponentiation: (a^b) % mod
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}

int inv(int x) {
    // Modular inverse using Fermat's Little Theorem: x^(mod-2) % mod
    return powr(x, mod - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // Hardcoded input
    string text = "ababbabbaba";
    string pattern = "aba";

    int pat_hash = poly_hash(pattern);  // Hash of the pattern

    int n = text.size(), m = pattern.size();

    // Compute the hash of the first substring of the text with length of the pattern
    int text_hash = poly_hash(text.substr(0, m));

    // If hashes are equal, the pattern starts at index 0
    if (pat_hash == text_hash) {
        cout << 0 << '\n';
    }

    // Use sliding window approach to check other substrings
    for (int i = 1; i + m <= n; i++) {
        // Remove the first character of the previous window
        text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
        // Multiply by the modular inverse of p
        text_hash = (text_hash * inv(p)) % mod;
        // Add the last character of the current window
        text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

        // If hashes are equal, print the index where pattern starts
        if (text_hash == pat_hash) {
            cout << i << '\n';
        }
    }

    return 0;
}
