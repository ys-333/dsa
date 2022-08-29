/*
    Problem Statement: Loweset Common Ancestor in a Binary
    Tree

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


bool findPath(Node *root,int n,vector<int>&path){
    if(root==NULL){
        return false ;
    }
    path.push_back(root->key) ;
    if(root->key==n){
        return true ;
    }
    if(root->left&&findPath(root->left,n,path)||root->right&&findPath(root->right,n,path)){
        return true ;
    }
    path.pop_back() ;
    return false ;
}

int Lca(Node *root,int n1,int n2){
    if(root==NULL){
        return -1 ;
    }
    vector<int>path1,path2 ;
    findPath(root,n1,path1) ;
    findPath(root,n2,path2) ;
    int i  ;
    for( i=0;i<path1.size()&&i<path2.size();i++){
        if(path1[i]!=path2[i]){
            break ;
        }
    }
    return path1[i-1] ;

}

int main(){
    Node *root = new Node(1) ;
    root->left= new Node(2) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    root->right = new Node(3) ;
    root->right->left =new Node(6) ;
    root->right->right = new Node(7) ;
    cout<<Lca(root,6,7) ;
    return 0 ;
}