/*
    Problem Statement:Check for BST.
    Efficient Solution: 
        1.Pass a range for every node.
        2.For root range is -infinity to +ve infinity.
        3.For left child of a node,we change upper bound as current
        nodes value.
        4.For right child of a node, we change lower bound as current node.
*/ 
/*
    There is another which is such that.
    When we traverse the bst in inorder fashion, then we push
    the each node in vector or array.
    Now we check wether our array or vector is sorted or not.
    If it's sorted we return true.
    Otherwise return false.
*/ 
#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    int lCount ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
        lCount = 0 ;
    }
} ;

bool isBst(Node *root,int lower_bound,int upper_bound){
    if(root==NULL){
        return true;
    }
    if(root->key<lower_bound||root->key>upper_bound){
        return false;
    }
    if(!isBst(root->left,lower_bound,root->key)||!isBst(root->right,root->key,upper_bound)){
        return false ;
    }
    return true ;
}

int main(){
    Node *root = new Node(20) ;
    root->left = new Node(8) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(9) ;
    root->right =new Node(30);
    root->right->left = new Node(22) ;
    root->right->right = new Node(35) ;
    
    return 0 ;
}


