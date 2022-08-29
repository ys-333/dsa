/*
    Problem Statement: Children Sum Property
    Input 1: Node *root = new Node(10);
               root->left = new Node(8) ;
               root->right = new Node(2) ;
               root->right->left = new Node(2) ;
    Output: Yes
*/

#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
bool childrenSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->key;
    }
    if (root->right != NULL)
    {
        sum += root->right->key;
    }
    return (root->key == sum && childrenSum(root->left) && childrenSum(root->right));
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(12);
    bool res = childrenSum(root);
    cout << res << endl;
    return 0;
}

/*
    This Approach will throw error during this input
    de *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->right = new Node(12);
    bool childrenSum(Node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return true;
    }

    childrenSum(root->left);
    childrenSum(root->right);
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->key;
    }
    if (root->right != NULL)
    {
        sum += root->right->key;
    }
    if (sum == root->key)
    {
        cout << sum << endl;
        return true;
    }
    else
    {
        return false;
    }
}

*/

/*
    Came with this approach during revison

    // Method 1 using level order traversal

    bool childrenSum(Node *root){
    if(root==NULL){
        return false ;
    }
    queue<Node*>q ;
    q.push(root) ;
    while(!q.empty()){
        int count = q.size() ;
        while(count>0){
            auto curr = q.front() ;
            q.pop() ;
            if(curr->left!=NULL&&curr->right!=NULL){
                if(curr->left->key+curr->right->key!=curr->key){
                    return false ;
                }
                q.push(curr->left) ;
                q.push(curr->right) ;
            }
            if(curr->left!=NULL&&curr->right==NULL){
                if(curr->key!=curr->left->key){
                    return false ;
                }
                q.push(curr->left) ;
            }
            if(curr->left==NULL&&curr->right!=NULL){
                if(curr->key!=curr->right->key){
                    return false ;
                }
                q.push(curr->right) ;
            }
            count-- ;
        }
    }
    return true;
}

// Method 2 using recursion

bool childrenSum(Node *root){
    if(root==NULL||root->left==NULL&&root->right==NULL){
        return true ;
    }
    else if(root->left!=NULL&&root->right!=NULL){
        if(root->left->key+root->right->key==root->key){
            return childrenSum(root->left)&&childrenSum(root->right) ;
        }
        
    }
    else if(root->left!=NULL&&root->right==NULL){
        if(root->key==root->left->key){
            return childrenSum(root->left)&&childrenSum(root->right) ;
        }
        
    }
    else{
        if(root->key==root->right->key){
            return childrenSum(root->left)&&childrenSum(root->right) ;
        }
    }
    return false ;
}

*/ 