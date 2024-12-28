#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
    unordered_set<int>s;
    for(auto itr:candies)
    {
        s.insert(itr);
    }
    int ans=min(s.size(),candies.size()/2);
    return ans;
}

int main(){
    vector<int> candies = {1,1,2,2,3,3};
    cout << "Number of people who can get candies: " << distributeCandies(candies)<<endl;
}