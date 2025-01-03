#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

int solve(int n,int k,vector<vector<int>> segments){
    vector<int>v[maxn];
    for(int i=0;i<n;i++){
        int x=segments[i][0],y=segments[i][1];
        v[x].push_back((i+1));
        v[y+1].push_back(-(i+1));
    }
    int cnt=0;
    set<pair<int,int>>cur;
    for(int i=1;i<maxn;i++){
        for(auto itr:v[i]){
            if(itr>0){
                cur.insert({-segments[itr-1][1],itr});
            }
            else{
                cur.erase({-segments[abs(itr)-1][1],-itr});
            }
        }
        while(cur.size()>k){
            cnt++;
            auto itr=cur.begin();
            cur.erase(itr);
        }
    }
    return cnt;
}

int main() {
    // Hardcoded input
    int n = 5; // Number of segments
    int k = 2; // Maximum allowed overlapping segments
    vector<vector<int>> segments = {
        {1, 4}, 
        {2, 5}, 
        {3, 6}, 
        {1, 3}, 
        {4, 7}
    };

    // Call the solve function and print the result
    cout << solve(n, k, segments) << endl;

    return 0;
}