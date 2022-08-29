/*
    Problem Statement: Fix a BST with two nodes swapped.
    Input:  
                        20
                        /\
                       60 80
                       /\  /\
                      4 10 8 100

    Output: Swap nodes with key 60 and 8 and print the new bst.
*/
#include<iostream>
#include<climits>
#include<vector>
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

/*
    In the previous method we did inorder travesal and push all the nodes 
    into vector.
    Then we traverse the vector and find out nodes which make the vector
    unsorted,since inorder traversal of bst would give sorted key.
    But since here two keys are swaped so we find out using traversal of vector.

    Since this method require  two times traversal of nodes,and O(n) extra space.

    So we go with the below method in which we traverse the nodes and
    compare the previous node with current node and that's how it go on.

    In this method we maintain prev,first and second.
    Prev just ensure that our bst property is maintain or not.
*/ 

Node *first=NULL,*second=NULL,*prevv = NULL ;
void swapNodes(Node *root){
    if(root==NULL){
        return ;
    }
    swapNodes(root->left) ;
    if(prevv!=NULL&&root->key<prevv->key){
        if(first==NULL){
            first = prevv ;
        }
        second = root ;
    }
    prevv = root ;
    swapNodes(root->right) ;
}

void inorder(Node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->key<<" " ;
    inorder(root->right) ;
}

int main(){
    Node *root = new Node(20) ;
    root->left = new Node(60) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(10) ;
    root->right =new Node(80);
    root->right->left = new Node(8) ;
    root->right->right = new Node(100) ;
   inorder(root) ;
    swapNodes(root) ;
    int temp = first->key ;
    first->key = second->key ;
    second->key = temp ;
    cout<<endl ;
    inorder(root) ;
    return 0 ;
}




    