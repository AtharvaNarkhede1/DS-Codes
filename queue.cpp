//basic functions of queue in C++

#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<string> q;

    q.push("a");
    q.push("b");
    q.push("c");

    cout<<"front element of queue: "<<q.front()<<endl; //front element of queue
    cout<<"back element of queue: "<<q.back()<<endl; //back element of queue

    q.pop(); //removes the front element

    cout<<"front element of queue: "<<q.front()<<endl; //front element of queue

    cout<<"size of queue: "<<q.size()<<endl; //size of queue
    

}