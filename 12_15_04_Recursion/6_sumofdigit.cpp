/*
    Problem Statement: Write a recursive function to find sum of
    digits in a number
*/
#include <iostream>
using namespace std;
int reverse(int n, int sum = 0)
{
    if (n == 0)
    {
        return sum;
    }
    int rem = n % 10;
    sum += rem;
    n /= 10;
    return reverse(n, sum);
}
int main()
{
    int n = 253;
    cout << reverse(n);
}