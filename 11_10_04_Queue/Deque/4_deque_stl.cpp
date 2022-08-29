/*
    STL implementaion of Deque STL
*/
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq{10, 20, 30};
    dq.push_front(5);
    dq.push_back(50);
    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << dq.front() << " " << dq.back() << endl;
    cout << "***********************************" << endl;
    auto it = dq.begin();
    it++;
    dq.insert(it, 20); // insert element just before the current operator
    dq.pop_front();
    dq.pop_back();
    cout << dq.size();
    cout << "*****************************************" << endl;
    it = dq.begin();
    it = dq.insert(it, 7);
    it = dq.insert(it, 2, 3);
    it = dq.erase(it + 1);
    cout << *it << endl;
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    cout << endl;
    return 0;
}