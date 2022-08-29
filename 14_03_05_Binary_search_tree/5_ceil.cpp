/*
    Problem Statement: Find Ceil of Binary Search tree.

Input:                       
                       10
                      /  \
                    5     15
                          / \
                         12  30   
 
Output: x=14 ans =15
        x=3  ans =5
        x=40 ans=NULL
*/ 
#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;

// this is an iterative method as it has O(1) auxillary space
Node *ceil(Node *root,int value){
    Node *curr = root ,*res=NULL;
    while (curr!=NULL)
    {
        if(curr->key==value){
            return curr ;
        }
        else if(curr->key<value){
            curr = curr->right ;
        }
        else{
            res = curr ;
            curr = curr->left ;
        }
    }
    return res; 
}
int res = INT_MAX ;
int ceilInorder(Node *root,int value){
    if(root==NULL){
        return INT_MAX ;
    }
 int ceil1= ceilInorder(root->left,value) ;
 int ceil2 =  ceilInorder(root->right,value) ;
    if(root->key>value){
         res = min(res,root->key) ;
         
    }
    return min(ceil1,min(res,ceil2)) ; 
}
    

    
       
    
    
    
    

int main(){
    Node *root = new Node(10) ;
    root->left = new Node(5) ;
    root->right =new Node(15) ;
    root->right->left = new Node(12) ;
    root->right->right = new Node(30) ;
    // this caller functon is for iterative call
    // Node *curr = ceil(root,13) ;
    // if(curr!=NULL){
    //     cout<<curr->key ;
    // }
    // else{
    //     cout<<"No valid ceil exist in the current tree"<<endl ;
    // }
    cout<<ceilInorder(root,235) ;
    // cout<<res<<endl; 
}