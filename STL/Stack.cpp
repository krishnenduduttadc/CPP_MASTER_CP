#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> books;
    books.push("Java");
    books.push("C++");
    books.push("Python");
    books.push("JS");

    while(!books.empty()){
        cout<<books.top()<<endl;
        books.pop();

    }
}