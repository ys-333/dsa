/*
    Problem Statement: Delete Node with random pointer
    Input: 10 --> 20 -->30 --> 40 --> 50 -->NULL
    Output: 10 -->20 -->40 -->50 -->NULL;
*/ 
/*
    Hint: Node to be deleted will never be the last node
    Approach: Copy all data of next node in current
    Node till curr->next->next!=NULL
    Corner Case:
    If its the last node then we make the last node itself null
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
    cout<<"NULL"; 
}

// To delete any random node and we are not provided with head of linked list
void deleteRandomNode(Node *randomNode){

    Node *temp = randomNode->next;
    randomNode->data = randomNode->next->data;
    randomNode->next = temp->next;
    delete(temp) ;
    

    // Node *curr = randomNode ;
    // if(randomNode->next==NULL){
    //     randomNode = NULL;
    // }
    // while (curr->next->next!=NULL)
    // {
    //     /* code */
    //     curr->data = curr->next->data;
    //     curr = curr->next; 
    // }
    // curr->data = curr->next->data;
    // Node *temp = curr->next;
    // delete temp;
    // curr->next = NULL;
    /*
         while (curr->next!=NULL)
    {
       
        cout<<curr->data<<" ";
        curr->data = curr->next->data;
        prev = curr ;
        curr = curr->next; 
    }
    delete curr ;
  prev->next = NULL;
    */    
    
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
    temp5->next = NULL;
    deleteRandomNode(temp3);
    print(head);
    return 0;

}