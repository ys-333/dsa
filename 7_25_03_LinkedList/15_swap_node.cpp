/*
    Problem Statement: Pairwise Swap of a linked list
    Input: 1 --> 2 --> 3 --> 4
    Output: 2 --> 1 --> 4 --> 3
    Input: 1 --> 2 --> 3 --> 4 -->
    Output: 2 --> 1 --> 4 --> 3 --> 5
*/

#include <iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *next = NULL;
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
void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " -->";
        curr = curr->next;
    }
    cout << " NULL";
}

// Program to swap pair wise node of list

/*

*/

Node *pairSwap(Node *head)
{
    Node *curr = head, *prevFirst = NULL;
    int k = 2;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            curr = curr->next;
        }
        if (isFirstPass)
        {
            head = prev;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = pairSwap(head);
    print(head);
}

/*
    1.Store the curr data into temp.
    2.IN curr data put curr next data and in curr next data put temp
    3.Move the curr 2 nodes at a time since its pairwise swapping.
*/
/*


Node *pairSwap(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        // int temp = curr->data;
        // curr->data = curr->next->data;
        // curr->next->data = temp;
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
}
*/