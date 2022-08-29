/*
    Problem Statement: Delete node in bst.

    Approach:
    There could be three possible cases.
        1.The node to delete is leaf node.
        2.The node to delete has one child.
        3.The node ot delete has both the child.
    The interesting case is when, the node to delete have both the child.
    In that case we find the inorder predecesor which could replace the existing root 
    to
*/ 

#include<iostream>
using namespace std; 
struct Node{
    int key ;
    Node *left,*right ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
    }
} ;
void preorder(Node *root){
    if(root==NULL){
        return ;
    }

    cout<<root->key<<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}
// function to delete node in binary search 

// to find inorder predesesor of the given root

Node *inorderPredessor(Node *root){
    Node *curr = root->right ;
    while (curr!=NULL&&curr->left!=NULL)
    {
        curr = curr->left ;
    }
    return curr ;
}
    

Node *deleteNode(Node *root,int value){
    if(root==NULL){
        return root ;
    }
    if(root->key>value){
        root->left = deleteNode(root->left,value) ;
    }
    else if(root->key<value){
        root->right = deleteNode(root->right,value) ;
    }
    else{
        // this conditional handles when root is equal to value.
        if(root->left==NULL){
            Node *temp = root->right ;
            delete root ;
            return temp ;
        }
        else if(root->right==NULL){
            Node *temp = root->left ;
            delete root ;
            return temp ;
        }
        else{
            Node *curr = inorderPredessor(root) ;
            root->key = curr->key ;
            deleteNode(root->right,curr->key) ;
        }
    }
}

int main(){
    Node *root = new Node(50) ;
    root->left = new Node(30) ;
    root->right = new Node(70) ;
    root->left->left =new Node(20) ;
    root->left->right =new Node(40) ;
    root->right->left = new Node(60);
    root->right->right = new Node(80) ;
    Node *root =  deleteNode(root,20) ;

}

/*
    //Recursive Solution

    // Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node (int data){
        key = data ;
        left = right =NULL ;
    }
};

// to insert the element in sorted fashion to make the time complexity O(logn)


void print(Node *root){
    if(root==NULL){
        return ;
    }
    print(root->left) ;
    cout<<root->key<<" ";
    print(root->right) ;
}

// This is to get the closest maximum number with respective to the current node  in  inorder fashino

Node *getClosest(Node *root,Node *parent){
    parent = root ;
    root = root->right ;
    while(root->left!=NULL){
        parent = root ;
        root = root->left ;
    }
    return parent ;
}

bool del(Node *root,Node*parent,int key){
    if(root==NULL){
        return false ;
    }
    if(root->key==key){
        // When its a leaf node
        if(root->left==NULL&&root->right==NULL){
            if(parent->left==root){
                parent->left=NULL ;
            }
            else{
                parent->right=NULL;
            }
            return true;
        }
        // When the node to be deleted has only one child either left or right 

        else if(root->left!=NULL&&root->right==NULL){
            root->key = root->left->key ;
            root->left=NULL ;
            return true ;
        }
        else if(root->left==NULL&&root->right!=NULL){
            root->key = root->right->key ;
            root->right=NULL;
            return true ;
        }
        
        // when the node to be deleted has both children
            In that case we look for closest maximum element and we replace it with the existing node.

        else{
            parent =  getClosest(root,parent) ;
            
            // This if the parent of closest maximum element is the root itself

            if(parent==root){
                root->key = parent->right->key ;
                root->right = parent->right->right ;
                return true ;
            }
            else{
                root->key = parent->left->key;
                parent->left=NULL ;
                return true ;
            }
        }
    }
    else if(root->key>key){
        return del(root->left,root,key) ;
    }
    else{
        return del(root->right,root,key) ;
    }
}


int main() {
    Node *root =new Node(50) ;
    root->left = new Node(30) ;
    root->left->left = new Node(20) ;
    root->left->right = new Node(40);
    root->right =new Node(70) ;
    // root->right->left = new Node(60) ;
    root->right->right = new Node(80) ;
    Node *parent =NULL ;
    cout<<del(root,parent,50)<<endl ;
    print(root) ;
    return 0;
}
*/ 