/*
    Problem Statement: Iterative Preorder Traversal of node of tree
    Using stack Data Structure.
*/
#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    Node *left, *right;
    int key;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

void iterativePreorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}
// preorder traversal using concept of bfs,that is at
// any point of time we push the children of node into stack and then process it
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (s.empty() == false)
    {
        Node *curr = s.top();
        cout << curr->key << " ";
        s.pop();
        if (curr->right != NULL)
        {
            s.push(curr->right);
        }
        if (curr->left != NULL)
        {
            s.push(curr->left);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->left = new Node(60);
    iterativePreorder(root);
    return 0;
}