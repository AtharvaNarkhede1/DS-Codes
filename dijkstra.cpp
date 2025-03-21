#include<iostream>
#include<queue>

using namespace std;

int main(){
    //max heap
    priority_queue<int> max;

    //min heap
    priority_queue<int, vector<int>, greater<int>> min;

    max.push(1);
    max.push(2);
    max.push(3);
    max.push(4);

    cout<<"Size-> "<<max.size()<<endl;

    int n= max.size();

    for(int i=0;i<n;i++){
        cout<<max.top()<<" ";
        max.pop();
    }cout<<endl;


    min.push(1);
    min.push(2);
    min.push(3);
    min.push(4);

    cout<<"Size-> "<<min.size()<<endl;

    int m= min.size();

    for(int i=0;i<m;i++){
        cout<<min.top()<<" ";
        min.pop();
    } cout<<endl;


    cout<<"empty or not-> "<<max.empty()<<endl;
    cout<<"empty or not-> "<<min.empty()<<endl;

    
}