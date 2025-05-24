#include <stdio.h>

int modinv(int a, int m) {
    int res = 1, b = m - 2;
    while (b) {
        if (b & 1) res = 1LL * res * a % m;
        a = 1LL * a * a % m; b >>= 1;
    }
    return res;
}

int main() {
    int a = 3, m = 11; // Example values
    int inverse = modinv(a, m);
    printf("The modular inverse of %d modulo %d is %d\n", a, m, inverse);
    return 0;
}