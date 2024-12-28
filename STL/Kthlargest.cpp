#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    vector<int> nums = {4, 5, 8, 2};
    int k=3;
    cout<<findKthLargest(nums, k)<<endl;
}