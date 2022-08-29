/*
    Problem Statememnt: Detect and delete loop in linked list

*/ 
#include<iostream>
using namespace std;
struct  Node {
    int data ;
    Node *next = NULL ;
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node *insertEnd(Node *head,int key){
    Node *temp = new Node(key) ;
    if(head==NULL){
        return temp ;
    }
    Node *curr = head ;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void print(Node *head){
    if(head==NULL){
        return ;
    }
    Node *curr = head ;
    while(curr!=NULL){
        cout<<curr->data<<"-->" ;
        curr = curr->next ;
    }
}

// lets detect and delete the cycle in linked list
Node *detectAndDeleteLoop(Node *head){
    Node *slow = head,*fast =head ;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next ;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        cout<<"Loop does not exist in the linked list";
        return head;
    }
    slow =head;
    while (slow->next!=fast->next)
    {
        /* code */
        slow =slow->next;
        fast = fast->next;
    }
    // the first node of the loop
    cout<<fast->next->data<<endl ;
    fast->next = NULL;
    return head;
    
}

int totalNodeInCycle(Node *head){
    Node *slow = head,*fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        cout<<"Loop does not exist in the given linked list"<<endl ;
        return 0;
    }
    // as they both are on same node so from here we count the total nodes in the list
    int count = 1;
    cout<<fast->data<<endl ;
    while(slow->next != fast){
        count++ ;
        cout<<slow->data<<" " ;
        slow = slow->next;
    }
    return count ;
}
int main(){
    Node *head = new Node(10);
    Node *temp1 =new Node(20) ;
    Node *temp2 =new Node(30) ;
    Node *temp3 =new Node(40) ;
    Node *temp4 =new Node(50) ;
    Node *temp5 =new Node(60) ;
    head->next = temp1 ;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp1;
    // head = detectAndDeleteLoop(head) ;
    // print(head) ;
    cout<<"Total Nodes present in the given the given loop is "<<totalNodeInCycle(head) ;
    return 0;

}