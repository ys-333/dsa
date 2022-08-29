/*
    Problem Statement:Implement two stack in an array
*/

/*
    Approach:
    1.Think in term of space and try to make array cache friendly
*/

#include <iostream>
using namespace std;
class twoStack
{
    int arr[5];
    int curr1 = 0;
    int curr2;
    int s1;
    int s2;
    int cap;

public:
    twoStack(int n)
    {
        cap = n;
        curr1 = -1;
        curr2 = n;
        s1 = 0;
        s2 = 0;
    }
    void push1(int x)
    {
        curr1++;
        if (curr1 != curr2)
        {
            arr[curr1] = x;
            s1++;
        }
        else
        {
            curr1--;
            cout << "overflow 1" << endl;
        }
    };
    void push2(int x)
    {
        curr2--;
        if (curr1 != curr2)
        {
            arr[curr2] = x;
            s2++;
        }
        else
        {
            curr2++;
            cout << "overflow" << endl;
        }
    };
    void pop1()
    {
        if (curr1 == -1)
        {
            cout << "Underflow";
        }
        else
        {
            curr1--;
            s1--;
        }
    };
    void pop2()
    {
        if (curr2 == cap)
        {
            cout << "Underflow";
        }
        else
        {
            curr2++;
            s2--;
        }
    };
    int top1()
    {
        if (curr1 != -1)
        {
            return arr[curr1];
        }
    };
    int top2()
    {
        if (curr2 != cap)
        {
            return arr[curr2];
        }
    };
    int size1()
    {
        return s1;
    };
    int size2()
    {
        return s2;
    };
};
int main()
{
    int n = 5;
    twoStack s(n);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(4);
    s.push2(5);
    s.push2(30);
    cout << s.top1() << endl;
    cout << s.top2() << endl;
    cout << s.size1() << endl;
    cout << s.size2() << endl;
    s.pop1();
    s.pop2();
    cout << s.top1() << endl;
    cout << s.top2() << endl;
    return 0;
}