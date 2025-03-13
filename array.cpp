//basic array operations and functions

#include <iostream>
#include <array>
using namespace std;

int main(){

    int basic[3] ={1,2,3};

    array<int,4> a = {1,2,3,4};

    int size = a.size();
    for (int i = 0; i < size; i++){
        cout << a[i] << endl;
    }

    cout << "Element at 2nd index: " << a.at(2) << endl; //returns element at 2nd index
    cout<< "Empty or not: " << a.empty() << endl; //returns 0 if not empty
    cout << "First element: " << a.front() << endl;  //returns first element
    cout << "Last element: " << a.back() << endl;  //returns last element

    
}