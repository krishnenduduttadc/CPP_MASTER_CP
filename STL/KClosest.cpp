#include<bits/stdc++.h>
using namespace std;

bool mycompare(int a,int b){
    return a>b;
}

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int diff=abs(arr[i]-x);
        q.push({diff,arr[i]});
    }
    while(k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    sort(ans.begin(),ans.end(),mycompare);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> result = findClosestElements(arr, k, x);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}