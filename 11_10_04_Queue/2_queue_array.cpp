/*
    Problem Statement: Implement of queue using array.

    Implement Operation: enqueue() dequeue() getFront() getRear()
    size() isEmpty()
*/

#include <iostream>
using namespace std;
class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    int cap;

    // public:
    Queue(int n)
    {
        size = 0;
        cap = n;
        front = -1;
        rear = -1;
        arr = new int[n];
    }
    void enqueue(int x)
    {
        // in this queue is full and print overflow
        if (front == 0 && rear == cap - 1 || rear == front - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (rear != front - 1)
        {
            if (front == -1)
            {
                front++;
            }
            rear = (rear + 1) % cap;
            arr[rear] = x;
        }
        // as we have implemented queue using circualr array
        // so its no neccessary that front will always be 0
        // if (rear == cap - 1 && front != 0)
        // {
        //     rear = 0;
        //     arr[rear] = x;
        // }

        // else if (rear != front - 1)
        // {
        //     if(front==-1){
        //         front++ ;
        //     }
        //     rear++;
        //     arr[rear] = x;
        //     cout<<"executed"<<endl ;
        // }
        size++;
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        if (front != rear)
        {
            front = (front + 1) % cap;
        }
        else
        {
            front = -1;
            rear = -1;
        }
        size--;
    }
    int currsize()
    {
        return size;
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Empty Queue" << endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
};
int main()
{
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    //   q.enqueue(30) ;
    q.dequeue();
    q.dequeue();

    cout << q.front << endl;
    cout << q.rear << endl;
    q.enqueue(40);
    cout << "***********************" << endl;
    cout << q.front << endl;
    cout << q.rear << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << "**************************" << endl;
    q.enqueue(50);
    cout << q.front << endl;
    cout << q.rear << endl;
    q.enqueue(60);
    cout << q.front << endl;
    cout << q.rear << endl;
    q.enqueue(70);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.front << endl;
    cout << q.rear << endl;
    cout << q.currsize() << endl;
    q.enqueue(70);
    cout << q.front << endl;
    cout << q.rear << endl;
    cout << q.currsize() << endl;

    return 0;
}

/*
    This approach performs better for all operation
    except dequeue opertion where it takes O(n) time

    class Queue
{
    int front;
    int rear;
    int *arr;
    int cap;

public:
    Queue(int n)
    {
        cap = n;
        front = -1;
        rear = -1;
        arr = new int[n];
    }
    void enqueue(int x)
    {
        if (rear == cap - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = x;
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        if (front == rear)
        {
            front--;
            rear--;
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }
    int size()
    {
        if (front == -1)
        {
            return 0;
        }
        return (rear - front + 1);
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
            return 0;
        }
        return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty";
            return 0;
        }
        return arr[rear];
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
};
*/