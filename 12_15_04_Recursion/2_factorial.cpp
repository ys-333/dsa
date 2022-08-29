/*
    Problem Statement: Find Factorial of a number
*/
#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

// writing factorial code in tail recursive way

int factT(int n, int val = 1)
{
    if (n == 0)
    {
        return val;
    }
    return factT(n - 1, n * val);
}

int main()
{
    int n = 4;
    cout << fact(n);
    return 0;
}