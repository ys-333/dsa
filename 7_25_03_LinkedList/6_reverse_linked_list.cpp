/*
    Problem Statement = Reverse a linked list
    Input: 10 20 30 40 50
    Output: 40 30 20 10

    Input : NULL
    Output: NULL;


    Approach:
    1) use two pointer prev and curr
    2)prev points to null and curr point to head
    3)Then we make curr->next = prev
    4)prev = curr ;
    5)then we assign curr to next node of list

    So this is how we change the order of list

*/

#include <iostream>
#include <vector>
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

// to reverse a linked list
Node *reverse(Node *head)
{
    // two  variable
    Node *prev = NULL, *curr = head;
    if (head == NULL)
    {
        return head;
    }
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
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

/*  1) For Two travesal approach

    So I used dynamic array to store all data of list and
    then create list by adding data at end of list
    and using vector
*/

/*
    Node *reverse(Node *head)
{
    vector<int> v;
    Node *curr = head;
    while (curr != NULL)
    {
        v.push_back(curr->data);
        curr = curr->next;
    }
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = v.back();
        v.pop_back();
    }
    return head;

    // to traverse the vector from end and then create list again and sent it to main function
    // Node *reverseList = NULL;
    // for (int i = v.size() - 1; i >= 0; i--)
    // {
    //     reverseList = insertEnd(reverseList, v[i]);
    // }
    // return reverseList;
}

*/