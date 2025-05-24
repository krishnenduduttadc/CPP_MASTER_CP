#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, G = 3;
int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

void ntt(vector<int> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = power(G, (MOD - 1) / len);
        if (invert) wlen = power(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = 1LL * a[i + j + len/2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len/2] = (u - v + MOD) % MOD;
                w = 1LL * w * wlen % MOD;
            }
        }
    }
    if (invert) {
        int inv_n = power(n, MOD - 2);
        for (int &x : a) x = 1LL * x * inv_n % MOD;
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4}; // Example input
    int n = a.size();
    int m = 1;
    while (m < n) m <<= 1;
    a.resize(m);
    
    ntt(a, false); // Forward NTT
    cout << "NTT Result: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    ntt(a, true); // Inverse NTT
    cout << "Inverse NTT Result: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}