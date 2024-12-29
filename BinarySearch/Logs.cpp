#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int> a){
    int l=1,r=1e9,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(a[i]-1)/mid;
        }
        if(sum<=k){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int n,k;
    n=20;
    k=5;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
        }
        cout<<solve(n,k,a)<<endl;
        return 0;
}