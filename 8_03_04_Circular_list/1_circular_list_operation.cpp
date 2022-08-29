/*
    Problem Statement: Performing circular list operaation like Insertion(insert at end and insert at begin),Traversal and deletion
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// To insert node  at end of list

Node *insertEnd(Node *tail, int key)
{
    Node *temp = new Node(key);
    if (tail == NULL)
    {
        temp->next = temp;
        return temp;
    }
    //  It's an begin O(1) operation as we know the tail pointer of the circular linked list
    Node *next = tail->next;
    tail->next = temp;
    temp->next = next;
    tail = temp;
    return tail;
}

//  To insert Node at front of circular linked list

Node *insertStart(Node *tail, int key)
{
    Node *temp = new Node(key);
    if (tail == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node *head = tail->next;
    temp->next = head;
    tail->next = temp;
    return tail;
}

// To traverse the list and print it

void print(Node *tail)
{
    Node *head = tail->next;
    Node *curr = head;
    do
    {
        cout << curr->data << " --> ";
        curr = curr->next;
    } while (curr != head);
    cout << head->data;
}

int main()
{
    Node *tail = NULL;
    tail = insertStart(tail, 10);
    tail = insertStart(tail, 20);
    tail = insertStart(tail, 30);
    tail = insertStart(tail, 40);
    print(tail);
}