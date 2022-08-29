/*
    Problem Statement: Iterative Inorder Traversal of node of tree
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

void iterativeInorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
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
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    iterativeInorder(root);
    return 0;
}

/*
    Came with approach during revison

    void inorder(Node *root){
    if(root==NULL){
        return ;
    }
    Node *curr = root ;
    stack<Node*>s ;
    s.push(curr) ;
    while(s.empty()==false){
        while(curr!=NULL){
            curr = curr->left ;
            if(curr!=NULL){
                s.push(curr) ;
            }
        }
        if(curr==NULL){
            cout<<s.top()->key<<" " ;
        }
        curr = s.top()->right ;
        s.pop() ;
        if(curr!=NULL){
            s.push(curr) ;
        }
    }
}

*/ 