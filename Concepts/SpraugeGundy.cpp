#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, int> memo;

int grundy(int n) {
    if (n == 0) return 0;
    if (memo.count(n)) return memo[n];

    unordered_set<int> s;
    for (int i = 1; i * i <= n; ++i) {
        s.insert(grundy(n - i * i));
    }
    int g = 0;
    while (s.count(g)) ++g;

    return memo[n] = g;
}

int main() {
    // Test grundy for some values
    for (int i = 0; i <= 20; ++i) {
        cout << "grundy(" << i << ") = " << grundy(i) << '\n';
    }
    return 0;
}
