#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a){
    int turn=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(turn==0 && a[i]==0)
        {
            turn ^=1;
            ans++;
        }
        if(turn==1 && a[i]==1)
        {
            turn^=1;
            ans++;
        }
    }
    return ans;
}

int main(){
    int n;
    n=20;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        a[i]=rand()%2;
        }
    
    cout<<solve(n,a)<<endl;

}