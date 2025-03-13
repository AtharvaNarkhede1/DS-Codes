/*
1. Create v
2. Searchv
3. Update
4. Displayv
5. Minimum salaryv
6. Maximum salaryv
7. Find Average Salary – Compute the average salary of all employees.
8. Total number of employees
*/

#include <iostream>
using namespace std;

class Employee {
public:
    int data;
    Employee* left;
    Employee* right;

    Employee(int val) {
        data=val;
        left=NULL;
        right=NULL;
    }

    void create(Employee*& root, Employee* val) {
        if(root== NULL) {
            root= val;
            return;
        }
        if(val->data < root->data) {
            if(root->left == NULL) {
                root->left = val;
            }else{
                insert(root->left, val);
            }
        }else{
            if(root->right == NULL) {
                root->right = val;
            }else{
                create(root->right, val);
            }
        }
    }

    void search(Employee* root, int key) {
        while(root != NULL) {
            if(root->data == key) {
                return root;
            }else if(key < root->data) {
                root=root->left;
            }else{
                root= root->right;
            }
        }
        return NULL;
    }

    void inorder(Employee* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }

    void minsalary(Employee* root){
        current=root;
        while(current->left!=NULL){
            current=current->left;
        }
    }

    void maxsalary(Employee* root){
        current=root;
        while(current->right!=NULL){
            current=current->right;
        }
    }
};

int main() {
    Employee e;
    int ch, val;

    do{
        cout<<"Enter your choice";
        cout<<"1.Create\n2.Search\n3.Update\n4.Display\n5.Minimum Salary\n6.Maximum Salary\n7.Average Salary\n8.Total no of Employees\n";
        cin>>ch;
        switch(ch){
            case 1:
            cout << "Enter salary: ";
                cin >> val;
                e.create(val);
            break;

            case 2:
            cout << "Enter salary to search: ";
                cin >> val;
                cout << (e.search(val));
            break;

            case 3:
            cout << "Employees: ";
            e.display();
            break;

            case 4:
            break;

            case 5:
            cout << "Minimum salary: " << e.minsalary() << "\n";
            break;
            
            case 6:
            cout << "Maximum salary: " << e.maxsalary() << "\n";
            break;

            case 7:
            break;

            case 8:
            break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }while(ch!=9);
    return 0;
}
