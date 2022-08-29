/*
    Problem Statement: Searialize and desearlize a array.
    Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->right = new Node(30) ;
    
    Ouput:[10 20 -1 -1 30 -1 -1] where -1 represents NULL

    Approach:
        One approach is construct both inorder and preorder vector or
        array of tree using two traversal. So serialization part is done.

        Now using both inorder and preorder vector de-seralize it.
*/ 
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key=key ;
        left = right = NULL ;
    }
} ;
void serialize(Node *root,vector<int>&v){
    if(root==NULL){
        v.push_back(-1) ;
        return ;
    }
    v.push_back(root->key) ;
    serialize(root->left,v) ;
    serialize(root->right,v) ;
} 
int preIndex = 0 ;
Node *deserialize(vector<int>v,int n){

    if(v[preIndex]==-1){
        return NULL ;
    }
    Node *root = new Node(v[preIndex++]) ;
    root->left = deserialize(v,n);
    root->right = deserialize(v,n);
    return root ;
}
void printVector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" " ;
    }
}
int main(){
    Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->right = new Node(30) ;
    vector<int>v; 
    serialize(root,v) ;   
    Node *newRoot =  deserialize(v,v.size()) ;
    cout<<newRoot->key<<endl ;
    vector<int>newV ;
    serialize(root,newV) ;
    printVector(v) ;
    cout<<endl ;
    printVector(newV) ;
    
    
}