#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

int solve(int n,int k,vector<int> h){
    int cnt[maxn]={0};
    for(int  i=0;i<n;i++){
        cnt[0]++;
        cnt[h[i]]--;
    }
    for(int i=1;i<maxn;i++){
        cnt[i]+=cnt[i-1];
    }
    int ans=0;
    long long sum=0;
    for(int i=maxn-1;i>=0;i--){
        if(cnt[i]==n){
            ans+=(sum>0);
            break;
        }
        if(sum+ cnt[i]>k)
        {
            ans++;
            sum=cnt[i];
            continue;
        }
        sum+=cnt[i];
    }
    return ans;
}

int main(){
// Hardcoded input
    int n = 5; // Number of elements
    int k = 10; // Maximum sum allowed in one group
    vector<int> h = {1, 2, 3, 4, 5}; // Array of heights

    // Call the solve function and print the result
    cout << solve(n, k, h) << endl;


}