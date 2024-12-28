#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    // Remove file handling
    // freopen("input.txt", "r", stdin);  // Removed
    // freopen("output.txt", "w", stdout); // Removed

    // Example of using random number generation
    // Commented out to simulate hardcoded output
    // cout << rand() % 100 << '\n';
    // cout << rand() % 100 << '\n';
    // cout << rng() % 100;

    // You can hardcode any values you like here
    int n = 10;  // Hardcoded value for n

    clock_t tt = clock();

    // Run some logic for a while loop
    while (1) {
        clock_t z = clock() - tt;
        if ((double)z / CLOCKS_PER_SEC > 4.9) break;

        // Place your actual code here
        // Example: generate random numbers
        int random_val = rng() % 100;
        cout << "Random Value: " << random_val << endl;
    }

    return 0;
}
