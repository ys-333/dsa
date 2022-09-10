#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node (int data){
        left = right  =NULL ;
        key = data ;
    }
} ;

// Helper function to get height of tree

int count(Node *root){
    if(root==NULL){
        return 0 ;
    }
    return 1+count(root->left)+count(root->right) ;
}


bool Complete(Node *root){
    if(root==NULL){
        return false ;
    }
    
    bool notComplete = false ;
    queue<Node*>q ;
    q.push(root) ;
    while(q.empty()==false){
        int count = q.size() ;
        while(count>0){
            Node *temp = q.front() ;
            q.pop() ;
            if(temp->left!=NULL){
                if(notComplete){
                    return false;
                }
                q.push(temp->left) ;
            }
            else{
                notComplete = true ;
            }
            if(temp->right!=NULL){
                if(notComplete){
                    return false;
                }
                q.push(temp->right) ;
            }
            else{
                notComplete = true ;
            }
            count-- ;
        }
    }
    return true ;
}

bool completeRec(Node *root,int index,int totalNodes){
    if(root==NULL){
        return true ;
    }
    if(index>=totalNodes){
        return false ;
    }
    return completeRec(root->left,2*index+1,totalNodes)&&completeRec(root->right,2*index+2,totalNodes) ;
}

int main(){
   Node *root = new Node(1) ;
   root->left = new Node(2) ; 
   root->right = new Node(3) ;
   root->left->left = new Node(4) ;
   root->left->right = new Node(5) ;
  root->right->left = new Node(6) ;
   root->right->right = new Node(7) ;
   
//   root->right->left = new Node(4) ;
    cout<<Complete(root)<<endl ;
    int totalNodes = count(root) ;
    cout<<completeRec(root,0,totalNodes)<<endl ;
    
}