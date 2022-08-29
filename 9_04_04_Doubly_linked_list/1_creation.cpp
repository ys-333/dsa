//  Problem Statement: To create insertBegin,insertEnd and all crud features of doubly linked list
#include <iostream>
using namespace std;

// structure of doubly list

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

// To insert at end of doubly linked list

Node *insertEnd(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

// To create function to insertBegin in doubly linked list

Node *insertBegin(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    head->prev = temp;
    return temp;
}

// To delete head of a linked list

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    Node *temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    delete temp;
    return head;
}

//  To print doubly linked list

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "-->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// To reverse a linked list

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head, *prev = NULL;
    while (curr != NULL)
    {

        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }

    return prev->prev;
}

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = reverse(head);
    print(head);
}