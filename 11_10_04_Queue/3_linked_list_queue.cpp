/*
    Problem Statement: Using Linked List implement queue.
*/ 
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next ;
    Node *prev ;
   
    int size ;
    Node(int data){
        size = 0 ;
        this->data = data;
        next=prev=NULL; 
    }
    

    
    
   
    int sizes(){
        return size ;
    }
    bool isEmpty(Node *head){
        if(head==NULL){
            return true ;
        }
        return false ;
    }
    
} ;

Node *push(Node *head,int x){
        Node *temp = new Node(x) ;
        if(head==NULL){
            temp->next = temp ;
            temp->prev = temp ;
            return temp ;
        }
        temp->next = head ;
        head->prev->next = temp ;
        temp->prev = head->prev ;
        head->prev = temp;
        return head ;
}

Node *pop(Node *head){
        if(head==NULL){
            cout<<"Queue is empty"<<endl ;
            return NULL ;
        }
        if(head->next==head){
            return NULL ;
        }
        Node *curr = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next ;
        delete curr ;
        return head;
        
}
 int getRear(Node *head){
        if(head==NULL){
            cout<<"Queue is empty"<<endl ;
            return -1 ;
        }
        return head->prev->data ;
}
int getFront(Node *head){
        if(head==NULL){
            cout<<"Queue is empty"<<endl ;
            return -1 ;
        }
        return head->data ;
}
void print(Node *head){
        if(head==NULL){
            cout<<"empty"<<endl ;
            return ;
        }
        Node *curr = head;
        while(curr!=head){
            cout<<curr->data<<" " ;
            curr = curr->next; 
        }
        cout<<endl ;
}
int main(){
 Node *head=NULL ;
 head = push(head,10) ;
 head = push(head,20) ;
 head = push(head,30) ;
 head = pop(head) ;
 head = pop(head) ;
 head = pop(head) ;
 cout<<getRear(head)<<endl ;
 cout<<getFront(head)<<endl ;
 
//  cout<<head->sizes()<<endl;
}