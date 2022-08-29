/*
    Problem Statement: Insert at beginnig of circualr list by not using tail pointer


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

void print(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data << " --> ";
        curr = curr->next;
    } while (curr != head);
}

// Efficient way of inserting node at start of list

/*
    1.We insert the new node between the head and hea->next and then swap the data of head and head->next which is now
    temp.
    So in thsi way we do not require to maintain the tail pointer can be inserted at front using only head
*/

Node *pushFront(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node *next = head->next;
    head->next = temp;
    temp->next = next;
    swap(head->data, temp->data);
    return head;
}

int main()
{
    Node *head = NULL;
    head = pushFront(head, 10);
    head = pushFront(head, 20);
    head = pushFront(head, 30);
    head = pushFront(head, 40);
    print(head);
}