/*
    Problem  Statement: Count Nodes in a Complete Binary tree.

    Approach: 
        1) When ever the node is perfect binary tree, we calculate
        the number of nodes by pow(2,h)-1.
        2) If it's not perfect binary tree then we calculate it's height
        by normal method 
*/ 

#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key = key ;
        left =right = NULL ;
    }
} ;
// this function calcuate the left and right height of respective root
int lh(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return 1+lh(root->left) ;
}
int rh(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return 1+rh(root->right) ;
}
int total(Node *root){
    if(root==NULL){
        return 0 ;
    }
    int leftHeight = lh(root) ;
    int rightHeight = rh(root) ;
    if(leftHeight==rightHeight){
        int totalNodes = pow(2,leftHeight) ;
        cout<<totalNodes<<endl ;
        return totalNodes-1 ;
    }
    else{
        return 1+total(root->left)+total(root->right) ;
    }
    cout<<"not executed"<<endl ;
}
int main(){
    Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->left->left = new Node(40) ;
    root->left->right = new Node(50) ;
    root->right = new Node(30) ;
    root->right->left = new Node(60) ;
    root->right->right = new Node(70) ;
    // cout<<lh(root)<<endl  ;
    // cout<<rh(root) ;
    cout<<total(root)<<endl ;
    return 0 ;
} 