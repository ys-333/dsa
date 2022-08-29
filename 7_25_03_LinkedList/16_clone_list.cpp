/*
    Problem Statement: Clone A linekd list

*/

#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
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
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// To clone a linked list with next and random pointer

/*
  1. We will traverse a list and create a same node as curr and set curr next to its copy

*/

Node *clone(Node *head)
{
    // Inserting Blue nodes or node with same data as of current node
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
    {
        Node *temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
    }
    // Blue node or clone node random assingnig
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
    }
    // now taking out clone list from original list
    Node *original = head, *copy = head->next;
    Node *temp = copy;
    while (original && copy)
    {
        original->next = original->next->next;
        copy->next = copy->next != NULL ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
int main()
{
    Node *head = new Node(10);
    // head->data = 10;
    Node *temp1 = new Node(5);
    Node *temp2 = new Node(20);
    Node *temp3 = new Node(15);
    Node *temp4 = new Node(20);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = NULL;
    head->random = temp2;
    temp1->random = temp3;
    temp2->random = temp3;
    temp3->random = temp2;
    temp4->random = temp3;
    cout << "Before Cloning" << endl;
    cout << temp4->random->data << endl;
    head = clone(head);
    cout << "After Cloning" << endl;
    cout << temp4->random->data << endl;

    print(head);
}

/*
    1.Intialize a hashmap ump with key as current node and value as new node with same data
    2.After that in second loop get access to clonelist data by using ump[curr] which will give key i.e same node associated with same data
    3.Then change the next and random as given

    This Solution takes
    Time Complexity: O(n)
    Space Complexity: O(n)

*/

// Node *clone(Node *head)
// {
//     unordered_map<Node *, Node *> ump;
//     for (Node *curr = head; curr != NULL; curr = curr->next)
//     {
//         // create new node as of same as given list
//         ump[curr] = new Node(curr->data);
//     }
//     for (Node *curr = head; curr != NULL; curr = curr->next)
//     {
//         Node *clone = ump[curr];
//         clone->next = ump[curr->next];
//         clone->random = ump[curr->random];
//     }
//     return ump[head];
// }