#include <bits/stdc++.h>
using namespace std;

char digitToChar(int digit)
{
    return digit + '0';
}

int charToDigit(char c)
{
    return c - '0';
}

string addNumbers(string n1, string n2)
{
    if (n1.length() > n2.length())
    {
        swap(n1, n2);
    }
    string res = "";
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    int carry = 0;
    for (int i = 0; i < n1.length(); i++)
    {
        int d1=charToDigit(n1[i]);
        int d2=charToDigit(n2[i]);
        int sum=d1+d2+carry;
        int op_digit=sum%10;
        carry=sum/10;
        res.push_back(digitToChar(op_digit));
    }

     for (int i = n1.length(); i < n2.length(); i++)
    {
        int d2=charToDigit(n2[i]);
        int sum=d2+carry;
        int op_digit=sum%10;
        carry=sum/10;
        res.push_back(digitToChar(op_digit));
    }

    if(carry){
        res.push_back('1');
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string n1="123456573224535675232323278908232434923938234113587654323219065431233331333";
    string n2="543216789034263787832322212122122245667833111123456780987653456987654456799";
    cout<<addNumbers(n1,n2)<<endl;
}