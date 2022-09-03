/*
    Problem Statement: Find Kth smallest element binary search tree.
*/ 
#include<iostream>
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
Node *insert(Node *root,int value){
    if(root==NULL){
        return new Node(value) ;
    }
    if(root->key>value){
        root->lCount+=1 ;
        root->left = insert(root->left,value) ;
    }
    else{
        root->right = insert(root->right,value) ;
    }
    return root ;
}
// print the root in inorder fashion
void inorder(Node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->lCount<<" " ;
    inorder(root->right) ;
}
// function to implement kth smallest element
Node *kthSmallestEl(Node *root,int k){
    if(root==NULL){
        return root ;
    }
    if(k==root->lCount+1){
        return root ;
    }
    if(root->lCount>=k){
        return kthSmallestEl(root->left,k) ;
    }
    else{
        return kthSmallestEl(root->right,k-root->lCount-1) ;
    }

}
int main(){
    int arr[] = {20,8,22,4,12,10,14};
    int n = sizeof(arr)/sizeof(arr[0]) ;
    Node *root = NULL;
    for(int x:arr){
        root = insert(root,x)  ;
    }
    // inorder(root) ;
    Node *kthNode = kthSmallestEl(root,7) ;
    cout<<kthNode->key<<endl ;
    return 0 ;
}

/*
    Node *insert(Node *root,int key){
    if(root==NULL){
        return new Node(key);
    }
    else if(root->key>key){
        root->lCount+=1 ;
        root->left = insert(root->left,key) ;
    }
    else{
        root->right = insert(root->right,key) ;
    }
    return root ;
}

int count =0  ;

Node *kthRoot(Node *root,int k){
    if(root->lCount-k==0||k==0){
        return root ;
    }
    else if(k<root->lCount){
        return kthRoot(root->left,k) ;
    }
    else{
        return kthRoot(root->right,k-root->lCount) ;
    }
}
*/ 