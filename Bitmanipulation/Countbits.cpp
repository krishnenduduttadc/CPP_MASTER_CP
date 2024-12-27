#include <bits/stdc++.h>
using namespace std;

int count_bits(int n){
    int cnt=0;
    while(n>0){
        int lbit=n&1;
        cnt+=lbit;
        n=n>>1;
    }
}

int main(){
    int n=10;
    cout<<count_bits(n)<<endl;
}