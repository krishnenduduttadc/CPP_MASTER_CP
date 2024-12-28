#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

vector<int> subsetsums(vector<int> a) {
    int n = a.size();
    vector<int> result;

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) sum += a[j];
        }
        result.push_back(sum);
    }

    return result;
}

int32_t main() {
    // Hardcoded input values
    int n = 5;
    int a = 3;
    int b = 10;
    vector<int> v = {1, 2, 3, 4, 5};

    // Divide the vector into two parts
    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        if (i <= n / 2) left.push_back(v[i]);
        else right.push_back(v[i]);
    }

    // Calculate subset sums
    vector<int> left_sums = subsetsums(left);
    vector<int> right_sums = subsetsums(right);

    // Sort the right subset sums
    sort(right_sums.begin(), right_sums.end());

    // Calculate the number of valid pairs
    int ans = 0;
    for (auto x : left_sums) {
        ans += upper_bound(right_sums.begin(), right_sums.end(), b - x) -
               lower_bound(right_sums.begin(), right_sums.end(), a - x);
    }

    // Print the result
    cout << ans << endl;

    return 0;
}
