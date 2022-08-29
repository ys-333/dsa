/*
    Problem statement: Linked List implementaion of Stack
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *head = NULL;
    int cap;
    Node(int data)
    {

        head = NULL;
        cap = 0;
        this->data = data;
        next = NULL;
    }
    void push(int x);
    void pop();
    int top();
    bool empty();
    int size();
};

void Node::push(int data)
{
    cap++;
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// to delete top of stack

void Node::pop()
{
    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    this->cap = cap + 1;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// to get top of stack

int Node::top()
{
    if (head == NULL)
    {
        cout << "No data in Stack" << endl;
        return -1;
    }
    return head->data;
}

// size

int Node::size()
{
    if (head == NULL)
    {
        cout << "Empty Stack" << endl;
        return -1;
    }
    return cap;
}

int main()
{
    Node s = NULL;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "size " << s.size() << endl;
    cout << "top " << s.top() << endl;
    s.pop();
    cout << "top " << s.top() << endl;
}