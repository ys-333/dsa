/*
    Problem Statement: Bottom view of binary tree.

    Input:
        Node * root = new Node(10) ;
        root->left = new Node(20) ;
        root->right =new Node(30);
        root->right->left =new Node(40);
        root->right->right =new Node(50);
    Output: 20 40 30 50
    Input:
        Node *root =  new Node(1) ;
        root->left = new Node(2) ;
        root->left->right = new Node(4) ;
        root->left->right->right = new Node(5) ;
        root->right = new Node(3) ;
    Output:
        2 4 5
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

void bottomViewR(Node *root,map<int,int>&m){
  queue<pair<Node*,int>>q; 
  q.push({root,0}) ;
  while(q.empty()==false){
      auto curr = q.front() ;
      Node *p =curr.first;
      int hd =curr.second;
      q.pop() ;
      m[hd] = p->key ;
      if(p->left!=NULL){
          q.push({p->left,hd-1}) ;
      }
      if(p->right!=NULL){
          q.push({p->right,hd+1}) ;
      }
      
  }
    
}

void bottomView(Node *root){
    map<int,int> m ;
    bottomViewR(root,m) ;
    // print the value of map m
    for(auto x:m){
        cout<<x.second<<" " ;
    }
       
}

int main(){
    Node *root =  new Node(10) ;
    root->left = new Node (20) ;
    root->right = new Node(50) ;
    root->left->left = new Node(30) ;
    root->left->right = new Node(40) ;
    root->right->left = new Node(60) ;
    root->right->right = new Node(70) ;
    // Node *root =  new Node(1) ;
    // root->left = new Node(2) ;
    // root->left->right = new Node(4) ;
    // root->left->right->right = new Node(5) ;
    // root->right = new Node(3) ;
    bottomView(root) ;
    return 0 ;
}
    
    
    
  