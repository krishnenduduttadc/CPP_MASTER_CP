#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int mod = 1e9 + 7;
const int sz = 51;

struct Mat
{
    int m[sz][sz];
    Mat() {
        memset(m, 0, sizeof m);
    }

    void eye() {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
    }

    Mat operator* (const Mat &a) const {
        Mat r;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
        return r;
    }
};

int32_t main() {

    // Hardcoded input
    int n = 3, k = 2;
    Mat a, res;

    // Hardcoded matrix
    a.m[0][0] = 1; a.m[0][1] = 2; a.m[0][2] = 3;
    a.m[1][0] = 4; a.m[1][1] = 5; a.m[1][2] = 6;
    a.m[2][0] = 7; a.m[2][1] = 8; a.m[2][2] = 9;

    res.eye();

    while (k) {
        if (k & 1ll) res = res * a;
        a = a * a;
        k /= 2;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += res.m[i][j];
            ans %= mod;
        }
    }

    cout << ans;

    return 0;
}
