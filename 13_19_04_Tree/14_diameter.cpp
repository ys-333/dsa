/*
    Problem Statement: Diameter of A tree.
   The longest path between 2 leaf nodes in BT.
*/
#include <iostream>
#include<unordered_map>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};
/*
    1. Find Diameter of main root
    2. Then find diameter of left and right child
    then return the maximum of all three
*/ 
int height(Node*root){
    if(root==NULL){
        return 0 ;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node *root){
    if(root==NULL){
        return 0 ;
    }
    int d1 = 1+height(root->left)+height(root->right) ;

    int d2 = diameter(root->left) ;
    int d3 = diameter(root->right) ;
    return max(d1,max(d2,d3)) ;
}

// this is time efficient solution as we pre compute the height of given tree
// and store in unordered map where key and value can be access in O(1) time

int diameterTimeEfficient(Node *root,unordered_map<Node*,int>&ump){
    if(root==NULL){
        return 0 ;
    }
    int d1 = 1+ump[root->left]+ump[root->right] ;
    int d2 = diameterTimeEfficient(root->left,ump) ;
    int d3 = diameterTimeEfficient(root->right,ump) ;
    return max(d1,max(d2,d3)) ;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    unordered_map<Node*,int>ump ;
    // cout << "The diameter of given tree is" << diameter(root);
    cout << "The diameter of given tree is" << diameterTimeEfficient(root,ump);
    return 0;
}