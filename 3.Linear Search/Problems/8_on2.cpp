#include <iostream>
using namespace std;
bool isPair(int arr[], int low, int high, int X)
{
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == X)
            return true;
        else if (sum > X)
            high--;
        else
            low++;
    }
    return false;
}
bool isTriplet(int arr[], int n, int X)
{
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, i + 1, n, X - arr[i]))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = isTriplet(arr, n, 32);
    cout << res << endl;
    return 0;
}