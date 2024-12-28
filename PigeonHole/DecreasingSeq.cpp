#include<bits/stdc++.h>
using namespace std;

int solve(int L,int R){
    if(R-L+1>L){
        return -1;
    }
    return R;
}

int main(){
    
    int L,R;
    L=20;
    R=10;
    cout<<solve(L,R)<<endl;
}