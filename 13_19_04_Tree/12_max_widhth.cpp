
/*
    Problem Statement: Maximum width of binary tree.
    Input: NULL
    Output: 0
    Input: Node *root = new Node(10) ;
            root->left = new Node(20) ;
            root->left->left = new Node(40) ;
            root->left->right = new Node(50) ;
            root->right = new Node(30) ;
            root->right->left = new Node(60) ;
    Output: 3
*/

#include <iostream>
#include <queue>
#include <climits>
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

int maxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int res = INT_MIN;
    while (!q.empty())
    {
        int n = q.size();
        res = max(res, n);
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->left = new Node(60);
    int res = maxWidth(root);
    cout << res << endl;
    return 0;
}