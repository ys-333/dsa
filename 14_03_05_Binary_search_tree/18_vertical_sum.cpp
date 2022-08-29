/*
    Problem Statement: Find vertical sum of binary tree.

    Input:  
                    10
                   /   \
                  20   50
                 / \
                30  40

    Output: 30 20 50 50
    
    Approach: We use map and and from the main function or caller function
    we sent three parameters that is horizontal distance which is 0 as default,
    and map.

*/ 

#include<iostream>
#include<map>
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

void verticalSumR(Node *root,int hd,map<int,int>&m){
    if(root==NULL){
        return ;
    }
    verticalSumR(root->left,hd-1,m) ;
    m[hd]+=root->key ;
    verticalSumR(root->right,hd+1,m) ;
}

int main(){
    Node * root = new Node(10) ;
    root->left = new Node(20) ;
    root->left->left = new Node(30) ;
    root->left->right = new Node(40) ;
    root->right =new Node(50);
    map<int,int>m ;
    verticalSumR(root,0,m) ;
    cout<<"The vertical sum of given tree are as follow"<<endl ;
    for(auto x:m){
        cout<<x.second<<" " ;
    }
    return 0 ;
}