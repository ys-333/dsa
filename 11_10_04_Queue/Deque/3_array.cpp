/*
    Implementing Deque usign circualr linked list
*/
#include <iostream>
using namespace std;
class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int cap;

public:
    Deque(int n)
    {
        front = -1;
        rear = -1;
        arr = new int[n];
        cap = n;
    }
    void pushFront(int x)
    {
        // conditon for overflow
        if (front == 0 && rear == cap - 1 || rear == front - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
            rear++;
            arr[front] = x;
        }
        else if (front == 0)
        {
            front = cap - 1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }
    }
    void pushBack(int x)
    {
        if (front == 0 && rear == cap - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        else if ((rear + 1) % cap != rear)
        {
            rear = (rear + 1) % cap;
            arr[rear] = x;
        }
    }
    int popFront()
    {
        if (front == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return -1;
        }
        else
        {
            front = (front + 1) % cap;
        }
        return arr[front];
    }
    int popBack()
    {
        if (rear == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return -1;
        }
        else if (rear == 0 && front != 0)
        {
            rear = cap - 1;
        }
        else
        {
            rear--;
        }
        return arr[rear];
    }
    int getFront()
    {
        if (front == -1)
        {
            return -1;
            cout << "No element in deque" << endl;
        }
        return arr[front];
    }
    int getBack()
    {
        if (rear == -1)
        {
            return -1;
            cout << "No element in deque" << endl;
        }
        return arr[rear];
    }
};
int main()
{
    Deque d(3);
    d.pushFront(10);
    d.pushFront(20);
    d.pushFront(30);
    cout << d.getFront() << endl;
    cout << d.getBack() << endl;
    cout << d.popFront() << endl;
    d.pushBack(40);
    cout << d.getFront() << endl;
    cout << d.getBack() << endl;
    cout << d.popBack() << endl;
    cout << d.popBack() << endl;
    cout << d.popBack() << endl;
}