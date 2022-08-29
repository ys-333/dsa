/*
    Problem Statement: Implement Stack using array
*/

#include <iostream>
using namespace std;

class Stack
{
public:
    int curr;
    int cap;
    int arr[256] = {0};
    Stack(int n)
    {
        cap = n;
        arr[n];
        curr = -1;
    }
    void push(int x);
    void pop();
    int top();
    int size();
    bool empty();
};

// implemetign push operation

void Stack::push(int x)
{
    if (curr == cap - 1)
    {
        cout << "Overflow" << endl;
        return;
    }
    curr++;
    arr[curr] = x;
}

// To delete top of stack

void Stack::pop()
{
    if (curr == -1)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        curr--;
    }
}
// to return size of stack

int Stack::size()
{
    if (curr == -1)
    {
        return 0;
    }
    return curr + 1;
}

// to return is stack empty or not

bool Stack::empty()
{
    if (curr == -1)
    {
        return true;
    }
    return false;
}

// Top of stack

int Stack::top()
{
    return arr[curr];
}

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "Size " << s.size() << endl;
    cout << s.empty() << endl;
    return 0;
}