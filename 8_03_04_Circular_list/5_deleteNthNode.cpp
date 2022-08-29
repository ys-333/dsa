/*
    Problem Statement: Delete Nth node from circular linked list


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
    cout << endl;
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

//  To insert at end of circular list just by usign head and not by maintaining extra tail pointer

/*
    1.Swap the data of temp and head.
    2.temp->next  = head->next
    3.head->next = temp
    4.return temp as new head

    As the last element is already pointing to head, so we make the head as new last and temp as new head of the list
*/

Node *pushEnd(Node *head, int key)
{
    Node *temp = new Node(key);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    swap(temp->data, head->data);
    temp->next = head->next;
    head->next = temp;
    return temp;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *temp = head->next;
    head->data = temp->data;
    head->next = temp->next;
    delete temp;
    return head;
}

// Delete Nth node form circular list

Node *deleteN(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // k==1 that mean head element
    if (k == 1)
    {
        Node *temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        delete temp;
        return NULL;
    }
    int count = 1;
    Node *curr = head;
    while (curr->next != head)
    {
        if (count == k - 1)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            break;
        }
        curr = curr->next;
        count++;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    head = pushEnd(head, 10);
    head = pushEnd(head, 20);
    head = pushEnd(head, 30);
    head = pushEnd(head, 40);
    print(head);
    deleteHead(head);
    deleteN(head, 3);
    print(head);
}