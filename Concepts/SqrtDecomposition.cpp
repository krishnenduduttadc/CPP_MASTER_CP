#include <iostream>
#include <cmath>
using namespace std;

const int N = 100000; // max array size
int a[N], block[N];
int B; // block size

void preprocess(int n) {
    B = (int) sqrt(n);
    for (int i = 0; i < n; i++)
        block[i / B] += a[i];
}

int query(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r;) {
        if (i % B == 0 && i + B - 1 <= r) {
            sum += block[i / B];
            i += B;
        } else {
            sum += a[i++];
        }
    }
    return sum;
}

int main() {
    int n = 10; // example size
    // initialize array a with example values
    for (int i = 0; i < n; i++)
        a[i] = i + 1; // 1, 2, 3, ..., 10

    preprocess(n);

    cout << "Sum of range [2, 6]: " << query(2, 6) << "\n"; // 3+4+5+6+7 = 25
    cout << "Sum of range [0, 9]: " << query(0, 9) << "\n"; // sum 1..10 = 55

    return 0;
}
