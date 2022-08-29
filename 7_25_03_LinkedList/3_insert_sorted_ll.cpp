// To insert in sorted list so that list is still is sorted
/*
    Input  =  10->20->30->40
    key = 25
    Output = 10 20 25 30 40
*/

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

// sorted insertion of element in list
Node *insertSorted(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        return temp;
    }
    if (key < head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (key >= curr->data && key <= curr->next->data)
        {
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next;
    }
    if (curr->next == NULL)
    {
        curr->next = temp;
    }
    return head;
}

// Insert in linked list at end
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

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertSorted(head, 15);
    head = insertSorted(head, 25);
    printLinkedList(head);
    return 0;
}