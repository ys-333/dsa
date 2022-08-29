/*
    Problem Statement: Recursively reverse the linked list.
*/ 
#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node *next ;
    Node(int data){
        this->data = data ;
        next = NULL;
    }
} ;
// Dry run the code everything will be clear.
Node *reverse(Node *root){

    if(root==NULL||root->next==NULL){
        return root ;
    }

    Node *newHead = reverse(root->next) ;

    root->next->next = root ;
    root->next = NULL ;
    return newHead ;
}
void printList(Node *root){
    if(root==NULL){
        return ;
    }
    Node *curr = root ;
    while(curr!=NULL){
        cout<<curr->data<<" " ;
        curr = curr->next ;
    }
    cout<<endl ;
}
int main(){
    Node *root =new Node(10) ;
    root->next = new Node(20) ;
    root->next->next = new Node(30) ;
    root->next->next->next = new Node(40) ;
    root =  reverse(root) ;
    printList(root) ;

}