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
        data = val;
        left = NULL;
        right = NULL;
    }

    // Create binary search tree
    void create(Employee*& root, Employee* val) { // Pass root by reference
        if (root == NULL) { // If null, insert val at root
            root = val;
            return;
        }
        if (val->data < root->data) { // If val is less than root
            if (root->left == NULL) {
                root->left = val;
            } else {
                create(root->left, val);
            }
        } else { // If val is greater than root
            if (root->right == NULL) {
                root->right = val;
            } else {
                create(root->right, val);
            }
        }
    }

    // Search for a key in the tree
    Employee* search(Employee* root, int key) {
        while (root != NULL) {
            if (root->data == key) {
                return root;
            } else if (key < root->data) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return NULL;
    }

    // Inorder traversal
    void inorder(Employee* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Find minimum salary
    int minsalary(Employee* root) {
        Employee* current = root;
        while (current->left != NULL) {
            current = current->left;
        }
        return current->data;
    }

    // Find maximum salary
    int maxsalary(Employee* root) {
        Employee* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->data;
    }
};

int main() {
    Employee* root = NULL; // Root of the tree
    int ch, val;

    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Create\n2. Search\n3. Display\n4. Minimum Salary\n5. Maximum Salary\n6. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter salary: ";
                cin >> val;
                Employee* newEmployee = new Employee(val);
                newEmployee->create(root, newEmployee);
                break;
            }
            case 2: {
                cout << "Enter salary to search: ";
                cin >> val;
                Employee* result = root->search(root, val);
                if (result != NULL) {
                    cout << "Employee with salary " << val << " found.\n";
                } else {
                    cout << "Employee with salary " << val << " not found.\n";
                }
                break;
            }
            case 3: {
                cout << "Employees (inorder traversal): ";
                root->inorder(root);
                cout << endl;
                break;
            }
            case 4: {
                cout << "Minimum salary: " << root->minsalary(root) << "\n";
                break;
            }
            case 5: {
                cout << "Maximum salary: " << root->maxsalary(root) << "\n";
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (ch != 6);

    return 0;
}
