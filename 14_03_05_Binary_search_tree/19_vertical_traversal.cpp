/*
    Problem Statement: Vertical traversal of tree.

    Input:
        Node * root = new Node(10) ;
        root->left = new Node(20) ;
        root->right =new Node(30);
        root->right->left =new Node(40);
        root->right->right =new Node(50);
    Output: 20
            10 40
            30
            50


    Input:
        Node *root = new Node(10) ;
        root->left = new Node(20) ;
        root->left->right = new Node(30) ;
        root->left->right->left = new Node(50) ;
    Output:
        20 50
        10 30
*/ 
#include<iostream>
#include<vector>
#include<queue>
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

void verticalI(Node *root,map<int,vector<int>>&m){
    queue<pair<Node*,int>>q ;
    q.push({root,0}) ;
    while (q.empty()==false)
    {
        auto curr = q.front() ;
        Node *p = curr.first ;
        int hd = curr.second ;
        if(p->left!=NULL){
            q.push({p->left,hd-1}) ;
        }
        if(p->right!=NULL){
            q.push({p->right,hd+1}) ;
        }
        m[hd].push_back(p->key) ;
        q.pop() ;
    }
    
}

void printVertical(Node *root){
    map<int,vector<int>> m ;
    verticalI(root,m) ;
    // print the value of map m
    for(auto x:m){
        for(int i=0;i<x.second.size();i++){
            cout<<x.second[i]<<" " ;
        }
        cout<<endl ;
    }
}

int main(){
    Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->left->right = new Node(30) ;
    root->left->right->left = new Node(50) ;
    printVertical(root) ;
    return 0 ;
}
    
    
    
  