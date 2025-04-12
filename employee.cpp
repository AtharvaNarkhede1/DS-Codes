#include<iostream>
#include<string>
using namespace std;

class Employee{ 
public:
    int id;
    string name;
    int salary;
    Employee* left;
    Employee* right; //emp id name salary declared

    Employee(int empId,string empName,int empSalary) {
        id =empId;
        name =empName;
        salary= empSalary;
        left =NULL;
        right = NULL;
    }
};

class EmployeeBST{
public:
    Employee* root; //creating root pointer
    
    EmployeeBST() {  //constructor for root pointer
        root=NULL;
    }

    void create(int id,string name,int salary){ //create node for new salary
        Employee* newNode= new Employee(id, name, salary);
        root=insert(root, newNode);
    }
    
    Employee* insert(Employee* root,Employee* val){
        if (root ==NULL){
            return val;
        }
        if (val->id < root->id){  // Sorting based on Employee ID
            root->left= insert(root->left,val);
        }else{
            root->right=insert(root->right,val);
        }
        return root;
    }
    
    Employee* searchById(Employee* root,int key){ //searching using id
        if(root==NULL ||root->id==key) {
            return root; // if tree is empty or root is key
        }
        if(key<root->id) {
            return searchById(root->left,key); //first search left then right side of tree
        }
        return searchById(root->right,key);
    }
    
    Employee* searchByName(Employee* root,string key){ //searching using name
        if(root==NULL){
            return NULL; //if tree is empty
        }
        if(root->name ==key){
            return root; //if root is key
        }
        Employee* leftSearch= searchByName(root->left,key);
        if (leftSearch) return leftSearch;
        return searchByName(root->right, key);
    }
    
    Employee* searchBySalary(Employee* root,int key){
        if(root==NULL) {
            return NULL; //if tree is empty
        }
        if(root->salary== key){
            return root; //if root is key
        }
        Employee* leftSearch=searchBySalary(root->left,key);
        if(leftSearch) return leftSearch;
        return searchBySalary(root->right,key);
    }

    void updateEmployee(int id, string newName, int newSalary) {
        Employee* emp = searchById(root, id); //using searchById fun searching employee to update
        if(emp){
            emp->name = newName; //replace name by newname
            emp->salary = newSalary; //salary by new salary
            cout << "Employee updated successfully!\n";
        } else {
            cout << "Employee not found!\n";
        }
    }

    void inorder(Employee* root){ //display in inorder form
        if(root == NULL){
            return; 
        }
        inorder(root->left);
        cout<<"ID: "<<root->id <<", Name: "<<root->name<<", Salary: "<<root->salary << "\n";
        inorder(root->right);
    }
    int minSalary(Employee* root) {
        if (root == NULL) return -1;
        while (root->left != NULL) {
            root = root->left;
        }
        return root->salary;
    }
    
    int maxSalary(Employee* root) {
        if (root == NULL) return -1;
        while (root->right != NULL) {
            root = root->right;
        }
        return root->salary;
    }   
    
    int sumSalary(Employee* root) {
        if (root == NULL) return 0;
        return root->salary + sumSalary(root->left) + sumSalary(root->right);
    }
    
    int countEmployees(Employee* root) {
        if (root == NULL) return 0;
        return 1 + countEmployees(root->left) + countEmployees(root->right);
    }
};

int main() {
    EmployeeBST tree; //object
    int ch, id, salary;
    string name;
    
    do {
        cout<<"\nEnter your choice:\n";
        cout<<"1. Create\n2. Search by ID\n3. Search by Name\n4. Search by Salary\n5. Display\n6. Min Salary\n7.Max salary\n8. Average Salaryz\n9. Total employees\n10. Update\n11.EXIT! \n";
        cin>> ch;
        
        switch (ch) {
            case 1: //take employee information in input
                cout<<"Enter Employee ID: ";
                cin>>id;
                cout<<"Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter Salary: ";
                cin>> salary;
                tree.create(id,name, salary);
                break;
            case 2: // use employee information to search [id]
                cout <<"Enter Employee ID to search: ";
                cin>>id;
                if (tree.searchById(tree.root, id)){
                    cout <<"Employee found!\n";
                } else {
                    cout<<"Employee not found!\n";
                }
                break;
            case 3: //use name for search
                cout<< "Enter Employee Name to search: ";
                cin.ignore();
                getline(cin, name);
                if (tree.searchByName(tree.root, name)){
                    cout<< "Employee found!\n";
                } else {
                    cout<< "Employee not found!\n";
                }
                break;
            case 4: //use salary for searching
                cout<<"Enter Employee Salary to search: ";
                cin>>salary;
                if (tree.searchBySalary(tree.root, salary)){
                    cout<<"Employee found!\n";
                } else {
                    cout<<"Employee not found!\n";
                }
                break;
            case 5:// inorder display
                cout<<"Employees in sorted order (by ID):\n";
                tree.inorder(tree.root);
                cout<< "\n";
                break;
            case 6:
                cout << "Minimum salary: " << tree.minSalary(tree.root) << "\n";
                break;
            case 7:
                cout << "Maximum salary: " << tree.maxSalary(tree.root) << "\n";
                break;
            case 8:
                if (tree.root) {
                    cout << "Average salary: " << tree.sumSalary(tree.root) / tree.countEmployees(tree.root) << "\n";
                } else {
                    cout << "No employees available.\n";
                }
                break;
            case 9:
                cout << "Total number of employees: " << tree.countEmployees(tree.root) << "\n";
                break;
            case 10:
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter New Salary: ";
                cin >> salary;
                tree.updateEmployee(id, name, salary);
                break;
            case 11:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }while(ch!= 11);
    
    return 0;
}

