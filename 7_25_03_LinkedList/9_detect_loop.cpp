/*
    Problem Statement: Detect Loop in a linked list
    Input: 10 --> 20 --> 30 --> 40 and then 40 point back to 20
    Output: True ;
    Input: head = NULL
    Output: False
    Input: 10 -> 20--> 30-->NULL
    Output: False

*/

/* FLOYD'S CYCLE DETECTION ALGORITHM*/
#include <iostream>
#include <unordered_set>
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

void printLoop(Node *head)
{
    for (int i = 0; i <= 4; i++)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

bool isLoop(Node *head)
{
    Node *slow_p = head, *fast_p = head;
    while (fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head;
    head->data = 10;
    Node *temp1 = new Node(20);
    head->next = temp1;
    Node *temp2 = new Node(30);
    temp1->next = temp2;
    Node *temp3 = new Node(40);
    temp2->next = temp3;
    temp3->next = NULL;

    bool res = isLoop(head);
    cout << res << endl;
    // printLoop(head);
    return 0;
}

/*
    Solution-1

     1) Created unordered set to keep track of Node
     2) If nodes did not exist in the set, then we insert it
     3) We come out op the while loop and return true;


    bool isLoop(Node *head)
{
    unordered_set<Node *> ump;
    Node *curr = head;
    while (ump.find(curr) == ump.end() && curr->next != NULL)
    {
        if (ump.find(curr) != ump.end())
        {
            return true;
            // cout << curr->data << " ";
            // ump.insert(curr);
        }
        ump.insert(curr) ;
        curr = curr->next;
    }
    return false
    // if (ump.find(curr) != ump.end())
    // {
    //     cout << endl;
    //     cout << ump.count(curr) << " ";
    //     cout << curr->data << " ";
    //     cout << "Yes" << endl;
    //     return true;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    // return false;
}

*/

/*

    Solution:2

    1) We run two loop and the inside loop check that
    curr->next has existed before or not
    2) So inner loop run from head to 1 node less than curr node
    3)If there exist node that is equal to curr->next->data,so we return true
    4) return false

    bool isLoop(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *tempCurr = head;
        Node *targetNode = curr->next;
        while (tempCurr != curr)
        {
            if (tempCurr->data == targetNode->data)
            {
                return true;
            }
            tempCurr = tempCurr->next;
        }
        curr = curr->next;
    }
    return false;
}
*/

/*

    Solution:3
    1)We maintain dummy Node.
    2) And we make each node next point to that dummmy node
    3) So if there is loop so the  element would be pointing to
    that dummy Node.
    4)If that happen then we return true
    5) Otherwise return false


*/

/*

    Solution:4
    In struct node we maintain visited variable of booleam type.
    So if we visit any node we sets it visited  = true which is false by default.


    bool isLoop(Node *head)
{
    Node *dummyNode = new Node(10);
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            return false;
        }
        if (curr->next == dummyNode)
        {
            return true;
        }
        Node *temp = curr->next;
        curr->next = dummyNode;
        curr = temp;
    }
    return false;
}

*/