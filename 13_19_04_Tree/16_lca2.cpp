/*
    Problem Statement: Loweset Common Ancestor in a Binary
    Tree using one Traversal

    Previous solution uses two traversal to get the least common ancestor and we used two 
    vector to store their path which not as efficent in space terms
    but here we do not use any space as like we used vector in previous solutino

    But space complexity would be O(h) due to call stack

    Node *root = new Node(1) ;
    root->left= new Node(2) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    root->right = new Node(3) ;
    root->right->left =new Node(6) ;

    Input: Lca(3,4)
    Output: 1
    Input: Lca(2,4)
    Output: 2
    
*/ 
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int key ;
    Node *left,*right;
    Node(int key){
        this->key =key ;
        left = right = NULL ;
    }
};


Node *Lca(Node*root,int n1,int n2)
{
    if(root==NULL){
        return NULL ;
    }
    if(root->key==n1||root->key==n2){
        return root ;
    }
    Node *lca = Lca(root->left,n1,n2) ;
    Node *rca = Lca(root->right,n1,n2) ;

    if(lca!=NULL&&rca!=NULL){
        return root ;
    }
    if(lca!=NULL){
        return lca ;
    }
    else{
        return rca ;
    }
}
int main(){
    Node *root = new Node(1) ;
    root->left= new Node(2) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    root->right = new Node(3) ;
    root->right->left =new Node(6) ;
    root->right->right = new Node(7) ;
    cout<<Lca(root,6,7)->key ;
    return 0 ;
}