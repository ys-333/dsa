/*
    Problem Statement: Tower of Hanoi
*/
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void towerOfHanoi(int n, char s, char d, char h)
{
    if (n == 0)
    {
        return;
    }
    cout << n << s << d << endl;
    towerOfHanoi(n - 1, s, h, d);
    cout << "Moving Rod " << n << " from " << s << " to " << d << endl;
    towerOfHanoi(n - 1, h, d, s);
}
int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}