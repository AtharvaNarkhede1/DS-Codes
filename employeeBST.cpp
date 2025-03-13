#include <iostream>
using namespace std;

class Employee {
public:
    int data;
    Employee* left;
    Employee* right;

    Employee(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class EmployeeBST {
public:
    Employee* root;
    
    EmployeeBST() {
        root = NULL;
    }

    void create(int val) {
        Employee* newNode = new Employee(val);
        root = insert(root, newNode);
    }
    
    Employee* insert(Employee* root, Employee* val) {
        if (root == NULL) {
            return val;
        }
        if (val->data < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    
    Employee* search(Employee* root, int key) {
        if (root == NULL || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return search(root->left, key);
        }
        return search(root->right, key);
    }
    
    void inorder(Employee* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
    int minSalary(Employee* root) {
        if (root == NULL) return -1;
        while (root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
    
    int maxSalary(Employee* root) {
        if (root == NULL) return -1;
        while (root->right != NULL) {
            root = root->right;
        }
        return root->data;
    }
    
    int sumSalary(Employee* root) {
        if (root == NULL) return 0;
        return root->data + sumSalary(root->left) + sumSalary(root->right);
    }
    
    int countEmployees(Employee* root) {
        if (root == NULL) return 0;
        return 1 + countEmployees(root->left) + countEmployees(root->right);
    }
};

int main() {
    EmployeeBST tree;
    int ch, val;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Create\n2. Search\n3. Update\n4. Display\n5. Minimum Salary\n6. Maximum Salary\n7. Average Salary\n8. Total Employees\n9. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter salary to insert: ";
                cin >> val;
                tree.create(val);
                break;
            case 2:
                cout << "Enter salary to search: ";
                cin >> val;
                if (tree.search(tree.root, val)) {
                    cout << "Employee found\n";
                } else {
                    cout << "Employee not found\n";
                }
                break;
            case 3:
                cout << "Update functionality not implemented.\n";
                break;
            case 4:
                cout << "Employees in sorted order: ";
                tree.inorder(tree.root);
                cout << "\n";
                break;
            case 5:
                cout << "Minimum salary: " << tree.minSalary(tree.root) << "\n";
                break;
            case 6:
                cout << "Maximum salary: " << tree.maxSalary(tree.root) << "\n";
                break;
            case 7:
                if (tree.root) {
                    cout << "Average salary: " << tree.sumSalary(tree.root) / tree.countEmployees(tree.root) << "\n";
                } else {
                    cout << "No employees available.\n";
                }
                break;
            case 8:
                cout << "Total number of employees: " << tree.countEmployees(tree.root) << "\n";
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 9);
    return 0;
}
