// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    int height ;
    Node(int data){
        key = data ;
        height = 1 ;
        left = right = NULL ;
    }
} ;

void print(Node *root){
    if(root==NULL){
        return ;
    }
    print(root->left) ;
    cout<<root->key<<" " ;
    print(root->right) ;
}

int height(Node *root)
{
    if(root==NULL){
        return 0 ;
    }
    return root->height ;
}

// to get balance factor

int balanceFactor(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return root->height ;
}

// left left case

Node *ll(Node *root){
    Node *temp = root ;
    root = root->left ;
    Node *right = root->right ;
    root->right = temp ;
    temp->left = right ;
    return root ;
}

// right right case
 
Node *rr(Node *root){
    Node *temp = root ;
    root = root->right ;
    Node *left = root->left ;
    root->left = temp ;
    temp->right = left ;
    return root ;
}

Node *tree(Node *root,int key){
    if(root==NULL){
        return new Node(key) ;
    }
    
    if(key<root->key){
        root->left = tree(root->left,key) ;
    }
    else if(key>root->key){
        root->right = tree(root->right,key) ;
    }
    
    
    int bf = balanceFactor(root->left)-balanceFactor(root->right) ;
    
    // left left case ---> left rotation
    
    if(bf>1&&key<root->left->key){
        return ll(root) ;
    }
    
    // right right case ->right rotation
    if(bf<-1&&key>root->right->key){
        return rr(root);
    }
    
    // right left case
    
    if(bf<-1&&key<root->right->key){
        ll(root->right) ;
        return rr(root) ;
    }
    
    if(bf>1&&key>root->left->key){
        rr(root->left) ;
        return ll(root) ;
    }
    return root ;
}


int main() {
    vector<int>v = {10,20,30,40,50,25} ;
    // vector<int>v = {20,15,5,40,50,18} ;
    Node *root = NULL ;
    for(int i=0;i<v.size();i++){
        root = tree(root,v[i]) ;
    }
    print(root) ;
    return 0;
}