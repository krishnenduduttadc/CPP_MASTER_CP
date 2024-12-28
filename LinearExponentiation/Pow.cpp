#include<bits/stdc++.h>
using namespace std;

string solve(int A,int B, int C){
    int sign1=(A<0 && C%2);
    int sign2=(B<0 && C%2);
    string ans;
    if(sign1!=sign2){
        ans=sign1? "<": ">";
    }
    else{
        if(abs(A)==abs(B)){
            ans="=";
        }
        else if((abs(A)<abs(B)) ^ sign1){
            ans="<";
        }
        else{
            ans=">";
        }
    }
    return ans;
}

int main(){
    int A,B,C;
    A=20;
    B=30;
    C=2;
    cout<<solve(A,B,C)<<endl;
    
}