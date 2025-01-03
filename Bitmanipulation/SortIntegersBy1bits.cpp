#include<bits/stdc++.h>
using namespace std;

bool comp(const int& a, const int& b){
    int c1 = __builtin_popcount(a);
    int c2 = __builtin_popcount(b);
    if(c1 == c2)
        return a < b;
    return c1 < c2;
}

vector<int> sortByBits(vector<int> arr) {
    sort(arr.begin(),arr.end(), comp);
    return arr;
}

int main(){
    vector<int> arr = {100, 10, 1, 1000};
    vector<int> result = sortByBits(arr);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}