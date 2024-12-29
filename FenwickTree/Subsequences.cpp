#include<bits/stdc++.h>
using namespace std;

// Update function for BIT
void update(int x, int n, vector<int>& bit) {
    while (x < n) {
        bit[x] += 1;
        x += x & -x;
    }
}

// Query function for BIT
int get(int x, vector<int>& bit) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

// Function to count smaller numbers to the right
vector<int> countSmaller(vector<int> nums) {
    int n = nums.size();
    vector<int> bit(n + 1);
    vector<int> temp = nums;

    // Coordinate compression
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        int val = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
        nums[i] = val + 1; // Map original numbers to their ranks
    }

    // BIT operations to calculate smaller counts
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int val = get(nums[i] - 1, bit);
        ans[i] = val;
        update(nums[i], n + 1, bit);
    }

    return ans;
}

// Main function
int main() {
    vector<int> nums = {5, 2, 6, 1}; // Example input
    vector<int> result = countSmaller(nums);

    // Output the result
    cout << "Count of smaller numbers to the right: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
