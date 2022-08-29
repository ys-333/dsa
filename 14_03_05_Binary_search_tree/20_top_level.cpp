/*
    Problem Statement: Top Level Of binary tree.

    Hint:In all this sort of problem horizontal distance is used.

    Input:
        Node *root =  new Node(10) ;
        root->left = new Node (20) ;
        root->right = new Node(50) ;
        root->left->left = new Node(30) ;
        root->left->right = new Node(40) ;
        root->right->left = new Node(60) ;
        root->right->right = new Node(70) ; 

    Output: 30 20 10 50 70 

    Input:
        Node *root =  new Node(1) ;
        root->left = new Node(2) ;
        root->left->right = new Node(4) ;
        root->left->right->right = new Node(5) ;
        root->right = new Node(3) ;

    Output: 2 1 3
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

void topLevelI(Node *root,int hd,map<int,int>&m){
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
        if(m.find(hd)==m.end()){
            m[hd] = p->key ;
        }
        q.pop() ;
            
    }
    
}

void topLevel(Node *root){
    map<int,int> m ;
    topLevelI(root,0,m) ;
    // print the value of map m
    for(auto x:m){
        cout<<x.second<<" " ;
    }
       
}

int main(){
    
    Node *root =  new Node(1) ;
    root->left = new Node(2) ;
    root->left->right = new Node(4) ;
    root->left->right->right = new Node(5) ;
    root->right = new Node(3) ;
    topLevel(root) ;
    return 0 ;
}
    
    
    
  