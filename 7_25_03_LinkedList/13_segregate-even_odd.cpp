/*
    Problem Statement: Segregate Even and odd nodes of linked list
    Input: 17 -->15-->8-->12-->10-->5-->4
    Output:8-->12-->10-->4-->17-->15-->5
*/
/*
    So here we are not using any extra space but modify the given list
*/ 
#include<iostream>
#include<list>
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

// segregating liked list into odd and even

Node *segregateList(Node *head){
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    for(Node *curr=head;curr!=NULL;curr = curr->next){
        if(curr->data%2==0){
            if(evenStart==NULL){
                evenStart = curr ;
                evenEnd = evenStart;
            }
            else{
                evenEnd->next = curr;
                evenEnd =evenEnd->next;
            }
        }
        else{
            if(oddStart==NULL){
                oddStart  = curr ;
                oddEnd = oddStart;
            }
            else{
                oddEnd->next = curr ;
                oddEnd = oddEnd->next;
            }
        }
    }
    if(evenStart==NULL||oddStart==NULL){
        return head;
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}

int main(){
    Node *head = NULL; 
    head = insertEnd(head,17) ;
    head = insertEnd(head,15) ;
    head = insertEnd(head,8) ;
    head = insertEnd(head,12) ;
    head = insertEnd(head,10) ;
    head = insertEnd(head,5) ;
    head = insertEnd(head,4) ;
    // to preserve the orginal list
    list<int> headCopy;
    for(Node *curr = head;curr!=NULL;curr = curr->next){
        headCopy.push_back(curr->data) ;
    }
    // to print the given nodt
    for(auto it = headCopy.begin();it!=headCopy.end();it++){
        cout<<*it<<" ";
    }

    head =  segregateList(head);
    print(head);
    return 0;

}