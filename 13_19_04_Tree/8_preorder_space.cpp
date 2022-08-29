/*
    Problem Statement: Iterative Preorder Traversal(Space Optimised Solution)

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

// Space optimised preorder traversal
void preorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr != NULL)
    {

        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right != NULL)
            {
                s.push(curr->right);
            }
            curr = curr->left;
        }
        if (!s.empty())
        {

            curr = s.top();
            s.pop();
        }
    }
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
    preorder(root);
}

/*
    Approach:
    1.Create an empty Stack st;
    and when we traverse the left children of node we push only
    right children of each node and thus we optimese the
    solution
*/