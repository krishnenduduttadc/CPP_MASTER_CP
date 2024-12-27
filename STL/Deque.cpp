#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq(10);
    for (int i = 0; i < 10; i++)
    {
        dq[i]=i*i;
    }
    for(auto x:dq){
        cout<<x<<endl;
    }
    
}