//vector basic operations and functions

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;

    vector<int> a(5,1); //5 elements with value 1
    for(int i:a){
        cout<<i<<endl;
    }

    
    cout<<"size: "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"size: "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"size: "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"size: "<<v.capacity()<<endl;
    cout<<"size: "<<v.size()<<endl;

    cout<<"Element at 2nd index: "<<v.at(2)<<endl; //returns element at 2nd index
    
    cout<<"front: "<<v.front()<<endl; //returns first element
    cout<<"back: "<<v.back()<<endl; //returns last element

    cout<<"before pop"<<endl;
    for(int i:v){
        cout<<i<<endl;
    }
    v.pop_back();

    cout<<"after pop"<<endl;
    for(int i:v){
        cout<<i<<endl;
    }

    cout<<"empty or not: "<<v.empty()<<endl; //returns 0 if not empty

}