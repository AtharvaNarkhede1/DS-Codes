//checking if two binary trees are identical or not

#include<iostream>
using namespace std;

//create two binary tree in 2 different classes 

int check(BT *P1, BT *P2){
    if(P1==NULL && P2==NULL){ //if both are null then return 1;
        return 1;
    }
    if(P1!=NULL && P2!=NULL){ // if both are not null then check for data and left and right child
        return (P1->data == P2->data && check(P1->left, P2->left) && check(P1->right, P2->right));
    }
    return 0;
}