/*
     Problem Statement: Insert in Binary tree.
*/ 
#include<iostream>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key=key ;
        left=right=NULL ;
    }
} ;
Node *insert(Node *root,int value){
    if(root==NULL){
       Node *curr = new Node(value);
        return curr ;
    }
    if(root->key==value){
        return root ;
    }
    else if(root->key>value){
        root->left = insert(root->left,value) ;
    }
    else{
        root->right = insert(root->right,value) ;
    }
    return root ;
}
// iterative insert
Node *insertI(Node*root,int value){
    Node *temp = new Node(value) ;
    Node *curr = root,*parent=NULL ;
    while (curr!=NULL)
    {
        parent=curr ;
        if(curr->key==value){
            return curr ;
        }
        else if(curr->key>value){
            curr = curr->left ;
        }
        else{
            curr = curr->right ;
        }
    }
    if(parent==NULL){
        return temp  ;
    }
    if(parent->key>value){
        parent->left =temp ;
    }
    else{
        parent->right = temp ;
    }
    return root ;
    
}
// end iterative insert
// preorder travesal of binary search tree
void preorder(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->key<<" "  ;
    preorder(root->left) ;
    preorder(root->right) ;
}
int main(){
    Node *root = new Node(10) ;
    root->left = new Node(5) ;
    root->right= new Node(15) ;
    root->right->left= new Node(12) ;
    root->right->right = new Node(18) ;
    root = insert(root,20) ;
    preorder(root) ;
    return 0 ;
}