/*
    Problem Statement:Pair with given sum in BST.

                        10
                        /\
                       8    20
                       /\  / \
                      4 9 11  30
                             /  
                            25

    output: Yes.
*/ 

/*
    Approach 1: Traverse the bst using inorder traversal.
                Push all nodes into vector.
                Then using two pointer find the pair since it's sorted array.
    Approach 2:
                Traverse the bst using inorder or preorder.
                Then for current root,search for sum-curr->key in bst.
                if that  exist return true ;
                return false.
    Approach 3:
                Using Hashing, unordered_set<key> s;
*/ 

#include<iostream>
#include<climits>
#include<vector>
#include<unordered_set>
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

bool search(Node *curr,int key){
    if(curr==NULL){
        return false;
    }
    if(curr->key==key){
        return true ;
    }
    if(curr->key>key){
        search(curr->left,key) ;
    }
    else{
        search(curr->right,key) ;
    }
}
// bool res;
// Node *root ;
// void pairSum(Node *curr,int sum){
//     if(curr==NULL){
//         return ;
//     }
//      res =  search(root,sum-curr->key) ;
//     if(res){
//         cout<<res<<endl ;
//         return ;
//     }
//     pairSum(root->left,sum) ;
//     pairSum(root->right,sum) ;
// }

// In the above method,we traverse the whole node even if we found the pair,
// so in this soulution we have optimise it.
// here we do not require extra space only the recursion call stack which is O(h) ;
Node *root ;
bool pairSum(Node *curr,int sum){
    // this way ensure that we  return only when we have true
    if(curr==NULL){
        return false ;
    }
    if(pairSum(curr->left,sum)==true){
        return true ;
    }
    if(search(root,sum-curr->key)==true){
        return true ;
    }
    // cout<<"this part won't be executed "<<endl ;
    return pairSum(curr->right,sum) ;
}

// Using Hashing

bool isPair(Node *root,int sum,unordered_set<int>&s){
    if(root==NULL){
        return false ;
    }
    if(isPair(root->left,sum,s)==true){
        return true ;
    }
    if(s.find(sum-root->key)!=s.end()){
        return true ;
    }
    else{
        s.insert(root->key) ;
    }
    return isPair(root->right,sum,s) ;
}

int main(){
    root = new Node(10) ;
    root->left = new Node(8) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(9) ;
    root->right =new Node(20);
    root->right->left = new Node(11) ;
    root->right->right = new Node(30) ;
    root->right->right->left = new Node(25) ;
    // cout<<pairSum(root,18) ;
    unordered_set<int>s ;
    cout<<isPair(root,18,s) ;

}