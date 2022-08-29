/*
    Problem Statement: Level Order Traversal line by line.
*/
#include <iostream>
#include <queue>
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
// here NULL mark the end end of the level so that we could
// print next level on next line
void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
        cout << curr->key << " ";
    }
}
// In this method we do not require null,we use two loop 

void printLevel(Node *root){
    if(root==NULL){
        return ;
    }
    queue<Node *>q;
    q.push(root);
    while (q.empty()==false)
    {
        int count =q.size() ;
        for(int i=0;i<count;i++){
            Node *curr = q.front() ;
            q.pop() ;
            cout<<curr->key<<" " ;
            if(curr->left!=NULL){
                q.push(curr->left) ;
            }
            if(curr->right!=NULL){
                q.push(curr->right) ;
            }
        }
        cout<<endl;
    }
    
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    printLevelOrder(root);
    return 0;
}