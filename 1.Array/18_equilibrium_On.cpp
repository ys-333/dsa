#include <iostream>
using namespace std;
int temp[] = {0};
bool isEquilibrium(int arr[], int n)
{
    int lSum = 0, rSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            lSum = 0;
            rSum = temp[n - 1] - temp[i];
        }
        else
        {
            lSum = temp[i - 1];
            rSum = temp[n - 1] - temp[i];
        }
        if (lSum == rSum)
            return true;
    }
    return false;
}
int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    // int arr[] = {4, 2, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // creating prefix array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        temp[i] = sum;
    }

    bool res = isEquilibrium(arr, n);
    if (res)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}