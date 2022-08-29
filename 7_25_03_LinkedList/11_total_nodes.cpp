/*
    Problem Statement: Total Nodes in the given cycle of  linked list
*/
/*
    Problem Statememnt: Detect and delete loop in linked list

*/
#include <iostream>
using namespace std;
struct Node
{
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
        cout << curr->data << "-->";
        curr = curr->next;
    }
}

// total Nodes in the given linked list which have cycle
/*
    This method is for only linked list with cycle
    1) First I will find the first intersection point of slow and fast pointer, i.e to detect whether loop
    exist or not in the array
    2) Then I will make slow point to head and then increment both slow and fast until slow->next==fast->next
    So this is the point where our first node of loop is.
    3) Then to count total Nodes i will make my slow points to head back and then I would traverse the list
    untill slow!=fast,where fast is at last and meanwhile increment count
    4)Then return count+1;
*/
int totalNodes(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        cout << "Loop does not exist in the given linked list" << endl;
        return 0;
    }
    // Now we will find first Node of the loop and last node too
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    int count = 1;
    //   cout<<slow->data<<endl;
    //   cout<<fast->data<<endl;
    slow = head;
    while (slow != fast)
    {
        /* code */
        count++;
        slow = slow->next;
    }
    return count;
}

// Total Node in cycle of list

int totalNodeInCycle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        cout << "Loop does not exist in the given linked list" << endl;
        return 0;
    }
    // as they both are on same node so from here we count the total nodes in the list
    int count = 1;
    cout << fast->data << endl;
    while (slow->next != fast)
    {
        count++;
        cout << slow->data << " ";
        slow = slow->next;
    }
    return count;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    Node *temp4 = new Node(50);
    Node *temp5 = new Node(60);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp3;

    cout << "Total Nodes present in the given the given Linked List is " << totalNodes(head);
    return 0;
}