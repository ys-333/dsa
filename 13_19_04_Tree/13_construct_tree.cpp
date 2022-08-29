/*
    Problem Statement: Construct Binary Tree when inorder and
    preorder array are given
    Input: in[] = {20,10,40,30,50}
            pr[] = {10,20,30,40,50}
*/
#include <iostream>
#include <unordered_map>
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
int preIndex = 0;
Node *cTree(int in[], int pr[], int is, int ie)
{
    if (is > ie)
    {

        return NULL;
    }
    Node *root = new Node(pr[preIndex++]);
    int inIndex;
    for (int i = is; i <= ie; i++)
    {
        if (root->key == in[i])
        {
            inIndex = i;
            break;
        }
    }
    // Now here we are recursively calling on left and right nodes of parent element
    root->left = cTree(in, pr, is, inIndex - 1);
    root->right = cTree(in, pr, inIndex + 1, ie);
    return root ;
}

int main()
{
    int in[] = {20, 10, 40, 30, 50};
    int pr[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    Node *root = cTree(in, pr, 0, n - 1);
    return 0;
}