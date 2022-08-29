/*
    Problem Statement: Given a rope of lenght n , we need ot find
    maximum number of pieces we can make such that length of
    every piece in in set {a,b,c} for given three values
    a,b and c.

    Input: n=5, a 2,=5,c=1 ;
*/
#include <iostream>
using namespace std;

int maximum(int a, int b, int c)
{
    int val = max(max(a, b), c);
    return val;
}
int maxCuts(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = maximum(maxCuts(n - a, a, n, c), maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c));
    if (res == -1)
    {
        return -1;
    }
    else
    {
        return res + 1;
    }
}
int main()
{
    int n = 23;
    int a = 11, b = 9, c = 12;
    int res = maxCuts(n, a, b, c);
    cout << res << endl;
    return 0;
}