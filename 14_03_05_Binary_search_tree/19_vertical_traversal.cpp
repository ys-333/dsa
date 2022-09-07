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
/*
    came with this approach during revison

    This approach is valid only for binary search tree.

    // Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    int hd ;
    Node (int key){
        this->key = key ;
        left = right = NULL ;
        hd = 0 ;
    }
     
} ;

void verticalSum(Node *root,int hd,map<int,int>&m){
    if(root==NULL){
        return ;
    }
    verticalSum(root->left,hd-1,m) ;
    m[hd]+=root->key ;
    verticalSum(root->right,hd+1,m) ;
}

void verticalTraversal(Node *root,int hd,map<int,set<int>>&m){
    if(root==NULL){
        return ;
    }
    verticalTraversal(root->left,hd-1,m) ;
    m[hd].insert(root->key) ;
    verticalTraversal(root->right,hd+1,m) ;
}

int main() {
   
    Node *root = new Node(1) ;
    root->left =  new Node(2) ;
    root->left->left =  new Node(4) ;
    // root->left->left->left =  new Node(40) ;
    root->left->right = new Node(5) ;
    // root->left->right->right = new Node(75) ;
    // root->left->right->right->right = n few Node(80) ;
    root->right = new Node(3) ;
    root->right->left = new Node(6) ;
    root->right->right = new Node(7) ;
    root->right->right->left = new Node(8) ;
    root->right->right->left->left = new Node(9) ;
    // root->left->right =  new Node(15) ;  
    // root->right = new Node(30) ;
    // root->right->left = new Node(11) ;
    // root->right->right = new Node(30);
    // root->right->right->left = new Node(25)
    // ;
    
    
    map<int,set<int>>m ;
    int hd = 0  ;
    verticalTraversal(root,hd,m) ;
    for(auto val:m){
        for(auto s:val.second){
            cout<<s<<" " ;
        }
        // sort(val.second.begin(),val.second.end()) ;
        // for(int i=0;i<val.second.size();i++){
        //     cout<<val.second[i]<<" " ;
        // }
        cout<<endl ;
    }
    // print(root) ;
    return 0;
}
    
    
    
    
    

*/ 
    
    
  