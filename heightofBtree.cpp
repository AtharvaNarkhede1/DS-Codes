#include<iostream>
using namespace std;


class BT{
public:
    int data;
    BT *left, *right;
    BT(int data){
        this->data = data;
        left = right = NULL;
    }
    BT(){
        data = 0;
        left = right = NULL;
    }

};
int height(BT *H){

    if(H==NULL){
        return 0;

        int left = height(H->left);
        int right = height(H->right);   
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }
}