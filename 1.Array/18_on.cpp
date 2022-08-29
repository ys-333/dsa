#include <iostream>
using namespace std;

bool isEquilibrium(int arr[], int n)
{
    int lSum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (lSum == sum - arr[i])
            return true;
        lSum += arr[i];
        sum -= arr[i];
    }
    return false;
}
int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    // int arr[] = {4, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

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