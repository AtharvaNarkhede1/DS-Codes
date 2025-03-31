#include<iostream>
using namespace std;

class BT {
    public:
    int data;
    BT* left;
    BT* right;

    BT(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    static BT* insert(BT* root) {
        cout << "Enter the value to insert (-1 for no node): ";
        int val;
        cin >> val;

        if (val == -1) {
            return NULL;
        }

        BT* newNode = new BT(val);
        cout << "Enter data for left of " << val << endl;
        newNode->left = insert(newNode->left);
        cout << "Enter data for right of " << val << endl;
        newNode->right = insert(newNode->right);

        return newNode;
    }
};

int main() {
    BT* root = NULL;

    // Creating a tree
    root = BT::insert(root);

    return 0;
}