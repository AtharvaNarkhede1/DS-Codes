//print all ancestors of a note in Binary Tree

#include <iostream>
using namespace std;

int traverse(BT *root, int target){
    if(root==NULL){
        return 0;
    }
    if(root->data == target){
        return 1;
    }
    if(traverse(root->left, target) || traverse(root->right, target)){
        cout<<root->data<<" ";
        return 1;
    }
    return 0;
}


//check tree is mirror of Binary Tree or not

#include <iostream>
using namespace std;

int ismirror(Node *R1, Node *R2){
    if(R1==NULL && R2==NULL){
        return 1; //true
    
    }
    if(R1!=NULL && R2==NULL){
        return 0; //false
    }

    if(R1->data != R2->data){
        if(ismirror(r1->left, r2->right) && ismirror(r1->right, r2->left)){
            return 1; //true
        }
        return 0;//false
    }
}


//convert binary tree to its mirror image

#include <iostream>
using namespace std;

void mirror(node *root)
{
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);
        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}



//construct a bianry tree from preorder and inorder traversal

#include <iostream>
using namespace std;

/* preorder= 1 2 4 8 9 10 11 5 3 6 7
    inorder= 8 4 10 9 11 2 5 1 6 3 7*/