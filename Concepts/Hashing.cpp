#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int P = 31;
const int MOD = 1e9 + 9;
vector<long long> pow_p, h;

void build_hash(string s) {
    int n = s.size();
    h.resize(n + 1, 0);
    pow_p.resize(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        h[i + 1] = (h[i] * P + s[i] - 'a' + 1) % MOD;
        pow_p[i + 1] = (pow_p[i] * P) % MOD;
    }
}

long long get_hash(int l, int r) {
    return (h[r] - h[l] * pow_p[r - l] % MOD + MOD) % MOD;
}

int main() {
    string s = "hellohash";
    build_hash(s);

    // Example: get hash of substring "hello" (indices 0 to 5)
    int l = 0, r = 5;
    cout << "Hash of substring \"" << s.substr(l, r - l) << "\": " << get_hash(l, r) << endl;

    // Example: get hash of substring "hash" (indices 5 to 9)
    l = 5, r = 9;
    cout << "Hash of substring \"" << s.substr(l, r - l) << "\": " << get_hash(l, r) << endl;

    return 0;
}
