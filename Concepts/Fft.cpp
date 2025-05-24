#include <iostream>
#include <vector>
#include <complex>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

// Recursive FFT
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[i*2];
        a1[i] = a[i*2+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    for (int i = 0; 2 * i < n; i++) {
        cd w = polar(1.0, 2 * PI * i / n * (invert ? -1 : 1));
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) a[i] /= 2, a[i + n/2] /= 2;
    }
}

// Helper function to print complex vector
void print_vector(const string& label, const vector<cd>& v) {
    cout << label << ": [";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "(" << v[i].real() << ", " << v[i].imag() << ")";
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Hardcoded input signal (must have length power of 2 for this implementation)
    vector<cd> signal = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    
    // Print original signal
    print_vector("Original Signal", signal);
    
    // Perform FFT
    fft(signal, false);
    print_vector("FFT Result", signal);
    
    // Perform inverse FFT
    fft(signal, true);
    print_vector("Inverse FFT Result (should recover original)", signal);
    
    return 0;
}