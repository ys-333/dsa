/*
    Problem Statement: Remove duplicate from a Sorted list
    Input: 10->20->20->30->30->30
    Output : 10->20->30
*/
/*
    Approach: To maintain current variable pointing to head
    1)curr->next->data = curr->data   then curr->next = curr->next->next
    3) else I incremnet curr
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
// print Node
void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
// To remove duplicates form the list
Node *removeDuplicate(Node *head)
{
    Node *curr = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // We need to deallocate the node which has to be removed
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 30);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = removeDuplicate(head);
    print(head);
    return 0;
}