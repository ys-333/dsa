/*
    Problem Statement: Search in Binary Search Tree.
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
// recursive
bool search(Node *root,int value){
    if(root==NULL){
        return false ;
    }
    if(root->key==value){
        return true ;
    }
    if(root->key>value){
        return search(root->left,value) ;
    }
    else{
        return search(root->right,value) ;
    }
}
// iterative
bool searchI(Node *root,int value){
    Node *curr = root ;
    while (root!=NULL)
    {
        if(curr->key==value){
            return true ;
        }
        else if(curr->key>value){
            curr = curr->left ;
        }
        else{
            curr = curr->right ;
        }
    }
    return false ;
    
}
// iterative end
int main(){
    Node *root = new Node(15) ;
    root->left = new Node(5) ;
    root->left->left = new Node(3) ;
    root->right= new Node(20) ;
    root->right->left= new Node(18) ;
    root->right->left->left= new Node(16) ;
    root->right->right = new Node(80) ;
    search(root,16) ;

}

    