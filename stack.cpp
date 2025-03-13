//basic operations of stack in C++

#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<string> s;

    s.push("a");
    s.push("b");
    s.push("c");

    cout<<"top element of stack: "<<s.top()<<endl;

    s.pop(); //removes the top element
    cout<<"top element : " <<s.top()<<endl;

    cout<<"size of stack: "<<s.size()<<endl;

    cout<<"is stack empty: "<<s.empty()<<endl;  //returns 1 if stack is empty else 0
}