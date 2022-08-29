/*
    Problem Statement: Implementing Dequeu using doubly
    linked list to maintain all operations with O(n) Time 
    complexity.
*/ 
#include<iostream>
using namespace std;
struct Node
{
    int data ;
    Node *next,*prev;
    Node(int x){
        data =x;
        next = prev=NULL ;
    }
};

struct Deque
{
    Node *front,*rear ;
    Deque(){
        front=NULL;
        rear=NULL;
    }
    void pushFront(int x){
        Node *temp =new Node(x) ;
        if(front==NULL){
            front=rear = temp ;
        }
        temp->next = front ;
        front->prev = temp ;
        front =temp ;
    }
    void pushBack(int x){
        Node *temp =new Node(x) ;
        if(rear==NULL){
            front=rear = temp ;
        }
        rear->next = temp ;
        temp->prev = rear ;
        rear = temp ;
    }
    void popFront(){
        if(front==NULL){
            cout<<"Deque is empty"<<endl ;
            return ;
        }
        Node *temp = front ;
        front = front->next ;
        front->prev = NULL ;
        delete temp ;
    }
    void popBack(){
        if(rear==NULL){
            cout<<"Deque is empty"<<endl;
            return ;
        }
        Node *temp = rear;
        rear = rear->prev;
        rear->next=NULL ;
        delete temp ;
    }
    int getFront(){
        if(front!=NULL){
            return front->data ;
        }
        return -1 ;
    }
    int getRear(){
        if(rear!=NULL){
            return rear->data ;
        }
        return -1 ;
    }
};


int main(){
    Deque q ;
    q.pushFront(10) ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.pushFront(20) ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.pushBack(30) ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.pushBack(40) ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.pushFront(50) ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.popFront() ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    q.popBack() ;
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
    
}