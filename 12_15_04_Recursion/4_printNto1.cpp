/*
    Problem Statement: Write a Recursive function to print
    numbers from n to 1.
*/
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    print(n - 1);
}
int main()
{
    int n = 5;
    print(n);
    return 0;
}