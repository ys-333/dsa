/*
    Problem Statement: Implementin stack using stl
*/
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << " Size " << s.size() << endl;
    cout << " Top " << s.top() << endl;
    s.pop();
    cout << "empty " << s.empty() << endl;
    s.push(50);
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
