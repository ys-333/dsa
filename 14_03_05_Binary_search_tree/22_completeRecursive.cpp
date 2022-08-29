/*
    Problem Statement: Find out whether bianry tree is complete or not.
    Input:
                    1
                    /\
                   2  3
                   /\
                  4  5
    Output: True

    Input:          1
                    /\
                   3  4
                   \
                   5
    Output: FALSE
*/ 
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int key ;
    Node *left,*right;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;

// to find total nodes in tree
int count(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return 1+count(root->left)+count(root->right) ;
}


bool isComplete(Node *root,int index,int totalnodes){
    if(root==NULL){
        return true ;
    }
    if(index>=totalnodes){
        return false ;
    }
    return isComplete(root->left,2*index-1,totalnodes)&&
    isComplete(root->right,2*index+2,totalnodes) ;
}


int main(){
    Node *root= new Node(10) ;
    root->left = new Node(20) ;
    root->right = new Node(30) ;
    root->left->left =new Node(40) ;
    root->left->right = new Node(50) ;
    root->right->right  = new Node(60) ;
    int totalNodes  = count(root);
    cout<<isComplete(root,0,totalNodes) ;
    return 0 ;
}