/*
    Problem Statement: Height of a Binary Tree.
*/ 
#include<iostream>
using namespace std;
struct Node{
    Node *left,*right ;
    int key ;
    Node(int x){
        key = x;
        left=right=NULL; 
    }
} ;
void inorder(Node *root){
   if(root==NULL){
       return ;
   } 
   inorder(root->left) ;
   cout<<root->key<<" " ;
   inorder(root->right) ;
}
int height(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return 1+max(height(root->left),height(root->right)) ;
}
int main(){
    Node *root =new Node(30) ;
    root->left =new Node(40) ;
    root->left->left =new Node(70) ;
    root->left->left->left =new Node(80) ;
    root->right = new Node(60) ;
    // inorder(root) ;
    cout<<height(root)<<endl ;
    return 0 ;
}
/*
    TestCase 1:
    Node *root =  NULL;
    ***********************************
    TestCase 2:
    Node *root =  new Node(10) ;
    root->left = new Node(8) ;
    root->right = new Node(30) ;
    root->right->right = new Node(50) ;
    root->right->right->left = new Node(70) ;
    root->right->left =new Node(40) ;
    inorder(root) ;
    ***************************************
*/ 