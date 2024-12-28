#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    int ans=0;
    priority_queue<int>q;
    q.push(a);
    q.push(b);
    q.push(c);
    while(q.size()>1)
    {
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        x--;
        y--;
        if(x){
            q.push(x);
        }
        if(y){
            q.push(y);
        }
        ans++;
    }
    return ans;
}

int main(){
    int a,b,c;
    a=10;
    b=5;
    c=10;
    cout<<maximumScore(a,b,c)<<endl;
}