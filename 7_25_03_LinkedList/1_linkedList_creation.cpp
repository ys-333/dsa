#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
// Insert in linked list
Node *insertBegin(Node *head, int key)
{
    Node *temp = new Node(key);
    temp->next = head;
    head = temp;
    return head;
}

// insert at end of linked list

Node *insertEnd(Node *head, int key)
{
    Node *temp = new Node(key);
    Node *curr = head;
    if (head == NULL)
    {
        return temp;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// delete first Nod of linked list
Node *delFirstNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

// Delete last Node of linked list
Node *delLastNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// Print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// recursive print of linked list
void rPrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    rPrint(head->next);
}

// search in linked list and get back index
int searchIndex(Node *head, int key)
{
    Node *temp = head;
    int index = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
int searchIndex(Node *head, int key, int index)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == key)
    {
        return index;
    }
    index++;
    return searchIndex(head->next, key, index);
}
int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = delLastNode(head);
    printLinkedList(head);
    // head = delFirstNode(head);
    // head = insertBegin(head, 10);
    // head = insertBegin(head, 20);
    // head = insertBegin(head, 30);
    // printLinkedList(head);

    // Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head->next = temp1;
    // temp1->next = temp2;
    // cout << temp2->data;
    // printLinkedList(head);
    // rPrint(head);
    // cout << searchIndex(head, 20, 1);
    return 0;
}