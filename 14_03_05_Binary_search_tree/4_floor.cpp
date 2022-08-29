/*
    Problem Statement: Floor in a BST.
    Input: x=14
            10
            /\
            5 15
               /\
              12 30 
    Output: Node 12

    Input: x=4
    Output: NULL ;

    Input: x=30
    Output: 30(same node)

    Input: x=100
    Output: Node 30
*/ 
#include<iostream>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;

// function for floor

/*
    This approach has Time complexity of O(h). When tree is skrewed tree,
    then our height will be same as total nodes  in the tree.
    Space Complexity: O(h).
    Since it would be storing  h function call in call stack function. 

*/ 
Node *floor(Node *root,int value){
    if(root==NULL){
        return NULL ;
    }
    if(root->key==value){
        return root ;
    }
    if(root->key>value){
        return floor(root->left,value) ;
    }

    // if we go to right,that means my value is greater as compared to current
    // node,so current node could be one possible answer
    Node *ans = floor(root->right,value) ;
    return ans!=NULL?ans:root ;
}

// Iterative method where space compleity or auxillary space is O(1).

Node *floorIterative(Node *root,int value){
    Node *curr = root ,*res;
    while (curr!=NULL)
    {
        if(curr->key==value){
            return curr ;
        }
        else if(curr->key>value){
            curr = curr->left ;
        }
        else{
            res = curr ;
            // cout<<curr->key<<" " ;
            curr = curr->right ;
        }
    }
    return res ;
    
}



int main(){
    Node *root = new Node(10) ;
    root->left = new Node(5) ;
    root->right = new Node(15) ;
    root->right->left = new Node(12) ;
    root->right->right = new Node(30) ;
    Node *res = floorIterative(root,17) ;
    if(res!=NULL){
        cout<<res->key ;
    }
    else{
        cout<<"It has no key"<<endl ;
    }
    // cout<<floor(root,11,root)<<endl ; 
    return 0 ;
}

/*
This was brute force approach i tried but it wont work for some cases
    int floor(Node *root,int value,Node *parent){
    // this if condition ensure when value falls between two node value.
    if(root->key<=value&&parent->key>=value||root->key>=value&&parent->key<=value){
        return root->key<parent->key?root->key:parent->key ;
    }
    if(root->left==NULL&&root->right==NULL){
        if(root->key<value){
            return root->key ;
        }
        else{
            return NULL ;
        }
    }
    if(root->key>value){
        return floor(root->left,value,root) ;
    }
    else if(root->key<value){
        return floor(root->right,value,root) ;
    }
}
*/ 

/*
    // Recursive approach

    Node *floor(Node *root,int x){
    if(root==NULL){
        return NULL ;
    }
    if(root->key==x){
        return root ;
    }
    else if(root->key>x&&root->left==NULL){
        return NULL;
    }
    else if(root->key<x&&root->right==NULL){
        return root;
    }
    if(x<root->key){
        return floor(root->left,x) ;
    }
    else{
        return floor(root->right,x) ;
    }
    
}

*/ 