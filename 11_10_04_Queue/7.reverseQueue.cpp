/*
    Problem Statement: Reverse a Queue.
    There are two approaches:-
        1) Iteratiev
        2) Recursive
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// iterative approach
void reverseI(queue<int> &q)
{
    stack<int> s;
    while (q.empty() == false)
    {
        /* code */
        s.push(q.front());
        q.pop();
    }
    while (s.empty() == false)
    {
        /* code */
        q.push(s.top());
        s.pop();
    }
}

// recursive approach
void reverseR(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverseR(q);
    q.push(x);
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    reverseI(q);
    cout << q.front() << " " << q.back() << endl;
    return 0;
}