/*
    Problem Statement = Find nth Node from end of linked list
    Input = 10 20 30 40 50
    N = 2
    Output = 40
    Input = 10 20 30
    N = 3
    Output = 10
    Input = 10 20
    N = 3
    Output = No Output
    Input = 10 20 30
    N = 1
    Output = 30

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

// Total element in the list
int totalNode(Node *head)
{
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// To find Nth Node from the end
int nodeFromEnd(Node *head, int n)
{
    Node *first = head, *second = head;
    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
        {
            return -1;
        }
        first = first->next;
    }
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    return second->data;
}
int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    cout << nodeFromEnd(head, 2);
}

// int nodeFromEnd(Node *head, int pos)
// {
//     int totalNodeList = totalNode(head);
//     int n = totalNodeList - pos;
//     if (n < 0)
//     {
//         cout << "Chck the size of array" << endl;
//         return -1;
//     }
//     Node *curr = head;
//     int index = 0; // to get hold of present node in which we are in loop
//     while (curr != NULL)
//     {
//         if (index == n)
//         {
//             return curr->data;
//         }
//         else
//         {
//             index++;
//             curr = curr->next;
//         }
//     }

// }

/*
    HINT:
        We will use two pointer technique
        1)Move 'first' n positon ahead
        2)Move 'second' pointer from head
        3)Move both 'first' and 'second' at same speed. Whe 'first'
        reaches NULL , second reaches the required Node .

*/