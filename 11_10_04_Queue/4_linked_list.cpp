/*
    In the previous statement we used doubly linked list
    but now will be implementing using singly linked list
*/ 
#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node *next ;
    Node(int x){
        data = x;
        next = NULL;
    }
} ;

struct Queue{
    Node *front,*rear ;
    Queue(){
        front=NULL ;
        rear = NULL ;
    }
    void enqueue(int x){
        Node *temp = new Node(x) ;
        if(front==NULL){
            front=rear=temp ;
            return ;
        }
        rear->next = temp ;
        rear = temp ;
    }
    // implementing dequeue operation
    void dequeue(){
        if(front==NULL){
            cout<<"empty"<<endl ;
            return ;
        }
        Node *prev_front = front ;
        front= front->next ;
        if(front==NULL){
            rear = NULL ;
        }
        delete prev_front ;
    }
    int getFront(){
        if(front==NULL){
            cout<<"Empty"<<endl ;
            return ;
        }
        return front->data ;
    }
    int getRear(){
        if(rear==NULL){
            cout<<"Empty"<<endl ;
            return ;
        }
        return rear->data ;
    }

} ;
int main(){

}
/*
    #include<iostream>
using namespace std;
struct Node {
    int data; 
    Node *next ;
    Node(int key){
        next = NULL ;
        data = key ;
    }
} ;
class Queue{
    Node *front,*rear ;
    int size ;
    public:
    Queue(){
        front = NULL ;
        rear = NULL ;
        size=0 ;
    }
    void push(int x) ;
    void pop() ;
    int  getFront() ;
    int getRear();
    int getSize() ;
    void print() ;
};
// to push the element into the queue
void Queue::push(int x){
    Node *temp = new Node(x) ;\
    size++ ;
    if(front==NULL){
        front = rear = temp ;
        return ;
    }
    rear->next = temp ;
    rear = temp ;
}
void Queue::pop(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl ;
        return ;
    }
    size-- ;
    if(front==rear){
        front=rear=NULL ;
    }
    else{
        Node *temp = front ;
        front = temp->next ;
        delete temp ;
    }
}
int Queue::getFront(){
    if(front!=NULL){
        return front->data ;
    }
    return -1 ;
}
int Queue::getRear(){
    if(rear!=NULL){
        return rear->data ;
    }
    return -1 ;
}
int Queue::getSize(){
    return size ;
}
void Queue::print(){
    if(front!=NULL){
        Node *curr = front ;
        while(curr!=NULL){
            cout<<curr->data<<" " ;
            curr = curr->next ;
        }
        cout<<endl ;
    }
}
int main(){
    Queue q ;
    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.print();
    q.pop() ;
    cout<<q.getSize()<<endl ;
    q.print();
    cout<<q.getFront()<<" "<<q.getRear()<<endl ;
}
*/ 