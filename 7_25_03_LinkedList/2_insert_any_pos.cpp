/*
    Problem Statement - > we have to insert at any position in linked list
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
// Insert in linked list at any pos

Node *insertPos(Node *head, int key, int pos)
{
    // to explicitly handle when we have to insert at very firs index
    Node *newNode = new Node(key);
    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    newNode->next = curr->next;
    curr->next = newNode;
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
    head = insertPos(head, 10, 1);
    head = insertPos(head, 20, 2);
    head = insertPos(head, 30, 3);
    head = insertPos(head, 40, 4);
    head = insertPos(head, 15, 2);

    printLinkedList(head);
    return 0;
}