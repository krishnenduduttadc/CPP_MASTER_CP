#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
bool isGoodArray(vector<int> nums) {
    int ans=0;
    for(auto itr:nums)
    {
        ans=gcd(itr,ans);
    }
    return ans==1;
}

int main(){
    int n;
    n=20;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        nums[i]=i+1;
    }
    cout<<isGoodArray(nums)<<endl;
    return 0;

}