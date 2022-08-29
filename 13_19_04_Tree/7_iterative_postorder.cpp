/*
    Problem Statement: Iterative Postorder traversal.

    Approach: Using two stack
*/
#include <iostream>
#include <stack>
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
void inorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (s.empty() == false || curr != NULL)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}
void preorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        // we are processing all left child node of the parent
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
    cout << endl;
}
void postorder(Node *root)
{
    Node *curr = root;
    stack<Node *> s1, s2;
    s1.push(root);
    while (s1.empty() == false)
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL)
        {
            s1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            s1.push(curr->right);
        }
    }
    // Now stack 2 contain our postorder fashion
    while (!s2.empty())
    {
        cout << s2.top()->key << " ";
        s2.pop();
    }
    cout << endl;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // inorder(root);
    // preorder(root);
    postorder(root);
    return 0;
}