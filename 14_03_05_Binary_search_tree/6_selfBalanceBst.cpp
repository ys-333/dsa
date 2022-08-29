/*
    Problem Statement: Create self bianry Search Tree from the given array.

Input: arr[] = {10,7,11,40,15,30,35}
Output:      
                        15
                      /    \
                    10      36
                    / \     /\
                  7     11 30 40

 

*/ 
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;

Node *selfBst(int arr[],int is,int ie){
    if(is>ie){
        return NULL ;
    }
    int mid = (is+ie)/2 ;
    Node *root = new Node(arr[mid]) ;
    root->left = selfBst(arr,is,mid-1) ;
    root->right = selfBst(arr,mid+1,ie) ;
    return root ;
}

void preorder(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->key<<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}
int main(){
    int arr[] = {10,7,11,40,15,30,35} ;
    sort(arr,arr+7) ;
    Node *root = selfBst(arr,0,6) ;
    preorder(root) ;
    return 0 ;
}