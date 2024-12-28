#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded) {
    int val=0,val1=0,n=encoded.size();
    vector<int>ans(n+1);
    for(int i=1;i<=n+1;i++)
    {
        val1^=i;
    }
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            val^=encoded[i];
        }
    }
    ans[0]=val^val1;
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]^encoded[i-1];
    }
    return ans;
}

int main(){
    vector<int> encoded = {1,2,3,4,5,6,7};
    vector<int> decoded = decode(encoded);
    for(int i=0;i<decoded.size();i++){
        cout<<decoded[i]<<" ";
    }
}