#include<bits/stdc++.h>
using namespace std;

int numDivisible(int l,int r, vector<int> arr){
	int ans=0,n=arr.size();
    
    for(int i=1;i<pow(2,n);i++){
    	long long lcm=1;
        int cnt=0;
        for(int j=0;j<n;j++){
        	int x=1<<j;
            if(i&x){
                lcm=(lcm*(long long)arr[j])/__gcd(lcm,(long long)arr[j]);
                cnt++;
            }
            if(lcm>r){
            	break;   
            }
        }
        if(lcm>r)
            continue;
        
        if(cnt%2){
        	ans+=r/lcm;
            ans-=(l-1)/lcm;
        }
        else{
            ans-=r/lcm;
            ans+=(l-1)/lcm;
        }
    }
	return ans;
}

int main(){
    int t,n,l,r;
    t=1;
    while(t--){
        n=10;
        l=5;
        r=3;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        cout<<numDivisible(l,r,arr)<<endl;
    }
}