/*
    Implementing Tree.
    Inorder Traversal -> Left Root Right
    Preorder Traversal -> Root Left Right
    Postorder Traversal ->Left Right Root
*/
#include <iostream>
using namespace std;
struct Node
{
    Node *left, *right;
    int key;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};
// Printing tree in format of inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root->left == NULL || root->right == NULL)
    {
        cout << root->key << " ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    inorder(root);
    // preorder(root);
    // postorder(root) ;
    return 0;
}