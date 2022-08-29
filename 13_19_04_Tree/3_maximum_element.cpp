/*
    Problem Statement: Maximum in Binary Tree.
*/
#include <iostream>
#include <climits>
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
void postorder(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->key << " ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}
void getMax(Node *root, int &maxEl)
{
    if (root == NULL)
    {
        return;
    }
    getMax(root->left, maxEl);
    getMax(root->right, maxEl);
    maxEl = maxEl < root->key ? root->key : maxEl;
}
int getMax(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}
int main()
{
    // Node *root = new Node(10);
    // root->left = new Node(80);
    // root->left->left = new Node(30);
    // root->left->right = new Node(40);
    // root->right = new Node(70);
    // root->right->left = new Node(80);
    // root->right->right = new Node(90);
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(400);
    root->right->right = new Node(50);
    // int maxEl = INT_MIN;
    // getMax(root, maxEl);
    // cout << maxEl << endl;
    int res = getMax(root);
    cout << res << endl;
    return 0;
}