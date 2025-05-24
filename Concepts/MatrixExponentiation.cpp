#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix mul(Matrix &A, Matrix &B, int mod) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % mod;
    return C;
}

Matrix pow(Matrix A, int p, int mod) {
    int n = A.size();
    Matrix res(n, vector<int>(n));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (p) {
        if (p & 1) res = mul(res, A, mod);
        A = mul(A, A, mod);
        p >>= 1;
    }
    return res;
}

void print_matrix(const Matrix &M) {
    for (const auto &row : M) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int mod = 1000000007;
    int power = 5;

    // Example 2x2 matrix
    Matrix A = {
        {1, 1},
        {1, 0}
    };

    cout << "Original Matrix:\n";
    print_matrix(A);

    Matrix result = pow(A, power, mod);

    cout << "\nMatrix raised to power " << power << ":\n";
    print_matrix(result);

    return 0;
}
