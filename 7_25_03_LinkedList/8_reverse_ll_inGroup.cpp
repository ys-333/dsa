/*
    Problem Statement = Reverse a linked list in group of K
    Input: 10 --> 20 --> 30 --> 40 --> 50 --> 60
    K=3
    Output: 30 --> 20 --> 10 --> 60 --> 50 --> 40->NULL

    Input : 10 --> 20 --> 30
    K=4
    Output: 30 --> 20 --> 10


    Approach:
    1) Reverse the whole linked list
    2) Declare index =1 and traverse the linked list at k position
    3)Then at k node make it next point to NULL
    4)Then travel the list to last and make last node next point to reverse list head
    5)and new head will be at k+1 pos

    So this is how we change the order of list

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
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
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

Node *reverseInGroup(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // here i need to explicily code to make my second list as head of the new pair wise swapped list
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        curr = curr->next->next;
        prev->next->next = prev;
    }
    prev->next = curr;
    return head;
}

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    head = insertEnd(head, 60);
    head = insertEnd(head, 70);
    head = reverseInGroup(head, 3);
    print(head);
}

// This is wrong method to implement

// Node *reverseInGroup(Node *head, int k)
// {
//     Node *headRev = reverse(head);
//     Node *lastNode = headRev;
//     for (int i = 0; i < k - 1; i++)
//     {
//         if (lastNode == NULL)
//             return headRev;
//         lastNode = lastNode->next;
//     }
//     // since it will be last node of real modify list and to its next we have our head
//     head = lastNode->next;
//     lastNode->next = NULL;
//     Node *curr = head;
//     while (curr->next != NULL)
//     {
//         curr = curr->next;
//     }
//     curr->next = headRev;
//     return head;
// }

/*
    Solution:2 Here we have used same method and reverse in pair of two
    Node *reverseInGroup(Node *head, int k)
{
    // We need to to have curr and prev as to reverse the k group
    //  We need to main prevfirst and curr first so that we could link
    Node *curr = head, *prevFirst = NULL;
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
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

*/