#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) { return (a + b) % MOD; }
int sub(int a, int b) { return (a - b + MOD) % MOD; }
int mul(int a, int b) { return 1LL * a * b % MOD; }

int main() {
    int num1 = 123456789;
    int num2 = 987654321;
    
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "MOD: " << MOD << endl << endl;
    
    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Subtraction: " << sub(num1, num2) << endl;
    cout << "Multiplication: " << mul(num1, num2) << endl;
    
    // Edge cases
    cout << "\nEdge cases:\n";
    cout << "Adding to overflow: " << add(MOD - 1, 1) << endl;
    cout << "Subtracting to underflow: " << sub(0, 1) << endl;
    cout << "Multiplying large numbers: " << mul(123456, 789012) << endl;
    
    return 0;
}