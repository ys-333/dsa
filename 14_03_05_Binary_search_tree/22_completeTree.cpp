/*
    Problem Statement: Find out whether bianry tree is complete or not.
    Input:
                    1
                    /\
                   2  3
                   /\
                  4  5
    Output: True

    Input:          1
                    /\
                   3  4
                   \
                   5
    Output: FAlse
*/ 
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int key ;
    Node *left,*right;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;
bool isComplete(Node *root){
    if(root==NULL){
        return true ;
    }
    queue<Node*>q ;
    q.push(root) ;
    while (q.empty()==false)
    {
        Node *curr= q.front() ;
        q.pop() ;
        if(curr->left!=NULL){
            q.push(curr->left) ;
        }
        else{
            if(curr->right!=NULL){
                return false ;
            }
        }
        if(curr->right!=NULL){
            q.push(curr->right) ;
        }
    }
    return true ;
}
int main(){
    Node *root= new Node(10) ;
    root->left = new Node(20) ;
    root->right = new Node(30) ;
    root->left->left =new Node(40) ;
    root->left->right = new Node(50) ;
    root->right->right  = new Node(60) ;
    cout<<isComplete(root) ;
    return 0 ;
}