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

/*
    1) Came with this approach during revision

    // Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<queue>
#include<map>
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


void print(Node *root){
    if(root==NULL){
        return ;
    }
    print(root->left) ;
    cout<<root->hd<<" " ;
    print(root->right) ;
}


void hd(Node *root,Node *parent){
    if(root==NULL){
        return ;
    }
    if(parent!=root&&parent->left==root){
        root->hd = parent->hd-1 ;
    }
    if(parent!=root&&parent->right==root){
        root->hd = parent->hd+1 ;
    }
    hd(root->left,root) ;
    hd(root->right,root) ;
}

void verticalSum(Node *root,map<int,int>&m){
    if(root==NULL){
        return ;
    }
    queue<Node*>q ;
    q.push(root) ;
    while(q.empty()==false){
        int count = q.size() ;
        while(count>0){
            auto temp = q.front() ;
            m[temp->hd]+=temp->key ;
            if(temp->left!=NULL){
                q.push(temp->left) ;
            }
            if(temp->right!=NULL){
                q.push(temp->right) ;
            }
            q.pop() ;
            count-- ;
        }
        cout<<endl ;
    }
}


int main() {
   
    Node *root = new Node(10) ;
    root->left =  new Node(15) ;
    root->left->left =  new Node(35) ;
    root->left->left->left =  new Node(40) ;
    root->left->right = new Node(20) ;
    root->left->right->right = new Node(75) ;
    root->left->right->right->right = new Node(80) ;
    root->right = new Node(25) ;
    // root->left->right =  new Node(15) ;
    // root->right = new Node(30) ;
    // root->right->left = new Node(11) ;
    // root->right->right = new Node(30);
    // root->right->right->left = new Node(25)
    // ;
    hd(root,root) ;
    map<int,int>m ;
    verticalSum(root,m) ;
    for(auto it:m){
        cout<<it.second<<" " ;
    }
    // print(root) ;
    return 0;
}
    
    
    
    
    
*/ 