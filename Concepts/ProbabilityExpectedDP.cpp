#include <iostream>
using namespace std;

const int N = 1000; // max size
double dp[N + 1];

int main() {
    int n = 10; // example length, can be changed

    dp[0] = 0;
    dp[1] = 0.5; // you need to initialize dp[1] since dp[i-2] for i=1 is dp[-1] invalid

    for (int i = 2; i <= n; ++i) {
        dp[i] = (1 + dp[i - 1] + dp[i - 2]) / 2.0;
    }

    // Print dp values
    for (int i = 0; i <= n; ++i) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    return 0;
}
