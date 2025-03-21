/*basic operations of set in C++ STL
//set stores unique element if store 4 5 times it will store it only one time
if inserted we cant modify element only insert or delete
returns in sorted order
in unordered set it is not sorted
unordered set is faster than set

*/

#include <iostream>
#include <set>
using namespace std;

int main(){
   set<int> s;

   s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);

    for(auto i:s){
        cout<<i<<endl;
    }
    
    set<int>::iterator it = s.begin();//currently at 0th index
    it++; // now at 0 + 1 index i.e 1st index 
    s.erase(it); // deletes 1st index element

    for(auto i:s){
        cout<<i<<endl;
    }

    cout<<endl;
    cout<<"Size-> "<<s.size()<<endl;
    cout<<"check if 5 is present or not "<<s.count(5)<<endl;
    cout<<"check if 10 is present or not "<<s.count(10)<<endl;
}