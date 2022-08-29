/*
    Problem Statement: Considser a situation where we have
    library available for queue and we need stack library.
    How to implement the stack using queue libarary.
*/
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;
    queue<int> push(int x)
    {
        q.push(x);
        return q;
    }
    queue<int> pop()
    {
        if (q.empty())
        {
            cout << "Empty queue" << endl;
            return q;
        }
        queue<int> cp;
        while (q.front() != q.back())
        {
            /* code */
            cp.push(q.front());
            q.pop();
        }
        return cp;
    }
    int top()
    {
        return q.front();
    }
    int size()
    {
        return q.size();
    }
};
int main()
{
}