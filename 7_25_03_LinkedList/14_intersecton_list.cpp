/*
    Problem Statement: Intersection Point of Two linked list
*/
/*
    !)Use unordered set to store all node of one list
    2)Then traverse the another list and using find stl function
    look for node in set and if it exist return data
    Otherwise False ;
*/
#include <bits/stdc++.h>
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
    cout << "NULL";
}

int count(Node *head)
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

int intersection(Node *head1, Node *head2)
{
    /*
       1) Calculate the lenght of both list
       2) Subtract their absloute value
       3)Now Move the larger list d times

       This method make sure that  we remoe all extra node in
       larger linked list and then traverse from d node
    */
    int c1 = count(head1);
    int c2 = count(head2);
    int d = abs(c1 - c2);
    Node *curr1 = head1, *curr2 = head2;
    if (c1 > c2)
    {

        for (int i = 0; i < d; i++)
        {
            curr1 = curr1->next;
        }
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 = curr2)
        {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    Node *temp4 = new Node(50);
    Node *temp5 = new Node(60);
    Node *head2 = new Node(4);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = NULL;
    head2->next = temp3;
    // print(head);
    // cout<<endl;
    // print(head2);
    cout << intersection(head, head2);
    return 0;
}

/*
    int intersection(Node *head1,Node *head2){
    unordered_set<Node*> ump ;
    for(Node *curr = head2;curr!=NULL;curr = curr->next){
        ump.insert(curr) ;
    }
    for(Node *curr = head1;curr!=NULL;curr = curr->next){
        if(ump.find(curr)!=ump.end()){
            return curr->data ;
        }
    }
    return -1;
}
*/