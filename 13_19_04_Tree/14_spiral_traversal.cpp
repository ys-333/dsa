/*
    Problm Statement:Tree Traversal in spiral form.
    Node *root = new Node(10) ;
    root->left = new Node(20) ;
    root->right = new Node(30);
    root->right->left = new Node(40) ;
    root->right->right = new Node(50) ;
    root->right->left->left = new Node(60) ;
    root->right->left->right = new Node(70) ;
    root->right->right->right = new Node(80) ;

    Output: 10 30 20 40 50 80 70 60

    Check for deque solution
*/
#include <iostream>
#include <deque>
#include <stack>
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
void spiralTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    deque<Node *> dq;
    dq.push_back(root);
    int level = 1;
    while (!dq.empty())
    {
        int count = dq.size();
        if (level % 2 == 0)
        {
            for (int i = 0; i < count; i++)
            {
                Node *curr = dq.back();
                dq.pop_back();
                if (curr->left != NULL)
                {
                    dq.push_front(curr->left);
                }
                if (curr->right != NULL)
                {
                    dq.push_front(curr->right);
                }
                cout << curr->key << " ";
            }
        }
        else
        {
            if (level % 2 == 0)
            {
                for (int i = 0; i < count; i++)
                {
                    Node *curr = dq.front();
                    dq.pop_front();
                    if (curr->left != NULL)
                    {
                        dq.push_back(curr->left);
                    }
                    if (curr->right != NULL)
                    {
                        dq.push_back(curr->right);
                    }
                    cout << curr->key << " ";
                }
            }
        }
        level++;
    }
}
// using stack
/*
    So in odd level we will push left  first and then right child
    And in even level we will push right and then left child
*/
void printSpiral(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s1;
    stack<Node *> s2;
    bool reverse = false;
    s1.push(root);
    while (s1.empty() == false || s2.empty() == false)
    {
        if (reverse == false)
        {
            int count = s1.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = s1.top();
                s1.pop();
                if (curr->left != NULL)
                {
                    s2.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    s2.push(curr->right);
                }
                cout << curr->key << " ";
            }
        }
        else
        {
            int count = s2.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = s2.top();
                s2.pop();
                if (curr->right != NULL)
                {
                    s1.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    s1.push(curr->left);
                }
                cout << curr->key << " ";
            }
        }
        reverse = !reverse;
    }
}
// 10 30 20 40 50 80 70 60
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);
    root->right->right->right = new Node(80);
    printSpiral(root);
    cout << endl;
    spiralTraversal(root);
    return 0;
}