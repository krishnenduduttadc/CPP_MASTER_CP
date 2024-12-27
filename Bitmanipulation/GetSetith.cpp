#include <bits/stdc++.h>
using namespace std;

int geti(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
void seti(int &n, int i)
{
    int mask = (1 << i);
    n = n | mask;
}

void cleari(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}
int main()
{
    int n = 5;
    int i = 2;
    cout << geti(n, i) << endl;
    seti(n,i);
}