/*
    Problem Statement:
        To count Number of nodes in binary tree
*/
#include <iostream>
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

// Approach 1
void totalNode(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
        return;
    }
    totalNode(root->left, count);
    totalNode(root->right, count);
    count++;
}
// Approach 2
int getCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + getCount(root->left) + getCount(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(80);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(80);
    root->right->right = new Node(90);
    int count = 0;
    totalNode(root, count);
    cout << count << endl;
    int res = getCount(root);
    cout << res << endl;
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);
}