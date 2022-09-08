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

/*
    In this method we store all node in vector no matter that is node with
    real value or null value,
    Then we traverse the node and see that if our previous was NULL and
    our current is a vaid root, then we return false as it is not a complete 
    binary tree.

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

    vector<Node*>v;

    void completeBinary(Node *root){
        if(root==NULL){
            return ;
        }
        queue<Node*>q ;
                v.push_back(root) ;
        q.push(root) ;
        while(q.empty()==false){
            int count = q.size() ;
            while(count>0){
                auto temp = q.front() ;
                v.push_back(temp->left) ;
                v.push_back(temp->right) ;
                
                if(temp->left!=NULL){
                    q.push(temp->left) ;
                }
                if(temp->right!=NULL){
                    q.push(temp->right) ;
                }
                q.pop() ;
                count-- ;
            }
        }
    }
        

    int main(){
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right= new Node(3) ;
    root->left->left = new Node(4) ;
    //   root->right->left = new Node(4) ;
    //   root->right->right= new Node(5) ;
    //   root->left->right = new Node(5) ;
    completeBinary(root);
    Node *prev = new Node(32132) ;
    for(int i=0;i<v.size();i++){
        
        if(v[i]==NULL){
            prev =NULL ;
        }
        else if(prev==NULL&&v[i]!=NULL){
            cout<<"not a complete binary tree "<<endl ;
            break ;
        }
    }
    }
*/ 