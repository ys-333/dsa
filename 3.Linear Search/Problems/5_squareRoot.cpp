/*
    Find square root of a number
    Input:
    N  = 14
    Output:
    3
    *****************
    N=28
    Output:
    5
*/
#include <iostream>
using namespace std;
int squareRoot(int n, int low, int high)
{
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int mSqaure = mid * mid;
        if (mSqaure <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n = 14;
    int root = squareRoot(n, 1, n);
    cout << root << endl;
    return 0;
}