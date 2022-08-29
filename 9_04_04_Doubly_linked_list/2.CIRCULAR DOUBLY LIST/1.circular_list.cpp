/*
    Problem Statement: To Implement Doubly linked list
*/

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

//  To insert at end of list

Node *insertEnd(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    head->prev->next = temp;
    temp->prev = head->prev;
    temp->next = head;
    head->prev = temp;
    return head;

    // Node *curr = head;
    // while (curr->next != head)
    // {
    //     curr = curr->next;
    // }
    // curr->next = temp;
    // temp->next = head;
    // temp->prev = curr;
    // head->prev = temp;
    // return head;
}

// To insert at begining of circular linked list

Node *insertBegin(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->next = head;
    head->prev->next = temp;
    temp->prev = head->prev;
    head->prev = temp;
    return temp;
}

// Print Circular Doubly linked list

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << "-->";
        curr = curr->next;
    } while (curr != head);
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);
    print(head);
    return 0;
}
