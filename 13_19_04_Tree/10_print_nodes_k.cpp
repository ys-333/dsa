/*
    Problem Staement: Print Nodes at distance k.
    
    Input 1:    Node *root = new Node(10) ;
                root->left = new Node(20) ;
                root->left->left = new Node(40) ;
                root->left->right = new Node(50) ;
                root->right = new Node(30) ;
                root->right->right = new Node(70) ;
    Input 2 :    Node *root = new Node(10); 
                root->left = new Node(20); 
                root->left->left = new Node(30);
*/ 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key =key ;
        left=right=NULL; 
    }
} ;
// same problem solve using recursion
void printnodes(Node *root,int k){
   if(root==NULL){
       return ;
   }
   if(k==0){
       cout<<root->key<<" ";
       return ;
   }
   printnodes(root->left,k-1) ;
   printnodes(root->right,k-1) ;
}
int main(){
  
   Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->left->left = new Node(40) ;
    root->left->right = new Node(50) ;
    root->right = new Node(30) ;
    printnodes(root,1) ; 
    // printnodes(root,0) ;
    return 0 ;
}

/*
This soultion involve concept of level order traversing the node
    Approach 1:
    void printnodes(Node *root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout<<root->key<<endl;
        return ;
    }
    int count =1;
    queue<Node*>q;
    q.push(root) ;
    while (q.empty()==false)
    {
        // cout<<count<<endl ;
        int n = q.size() ;
        for(int i=0;i<n;i++){
            Node *curr = q.front() ;
            q.pop() ;
            if(curr->left!=NULL){q.push(curr->left);} 
            if(curr->right!=NULL){q.push(curr->right) ;} 
        }
        if(count==k){
            while (q.empty()==false)
            {
                cout<<q.front()->key<<" " ;
                q.pop() ;
            }
            
        }
        count++ ;
    }
     
    
}
*/ 