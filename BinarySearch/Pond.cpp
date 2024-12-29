#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<vector<int>> grid){
    int l=0,r=1e9,mid,ans=-1;
    int x=(k*k)/2;
    x++;
    while(l<=r){
        mid=(l+r)/2;
        vector<vector<int>>pre(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>mid){
                    pre[i][j]=1;
                }
                if(i-1>=0){
                    pre[i][j]+=pre[i-1][j];
                }
                if(j-1>=0){
                    pre[i][j]+=pre[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    pre[i][j]-=pre[i-1][j-1];
                }
            }
        }
        int flag=0;
        for(int i=k-1;i<n;i++){
            for(int j=k-1;j<n;j++){
                int val=pre[i][j];
                if(i-k>=0){
                    val-=pre[i-k][j];
                }
                if(j-k>=0){
                    val-=pre[i][j-k];
                }
                if(i-k>=0 && j-k>=0){
                    val+=pre[i-k][j-k];
                }
                if(val<x){
                    flag=1;
                }
            }
        }
        if(flag){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){

int n = 3, k = 2; // Grid size and subgrid size
    vector<vector<int>> grid = {
        {1, 3, 7},
        {5, 6, 2},
        {9, 4, 8}
    };

    // Call the solve function
    int result = solve(n, k, grid);

    // Output the result
    cout << "The minimum median value for the given subgrid size is: " << result << endl;

    return 0;
        
}