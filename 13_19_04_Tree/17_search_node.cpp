/*
    Problem Statement: Given a tree and node,the task
    is to find the parent of given node in a tre.
    If the given node is tree then print -1;
*/

#include <iostream>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
    Node(int data)
    {
        this->key = data;
        left = right = NULL;
    }
};
void findParent(Node *root, int value, int parent)
{
    if (root == NULL)
    {
        return;
    }
    if (root->key == value)
    {
        cout << parent << endl;
        return;
    }
    findParent(root->left, value, root->key);
    findParent(root->right, value, root->key);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int node = 3;
    findParent(root, node, -1);
    return 0;
}