#include <iostream>
using namespace std;
bool isEquilibrium(int arr[], int n)
{
    int lSum = 0, rSum = 0;
    for (int i = 0; i < n; i++)
    {
        lSum = 0, rSum = 0;
        for (int j = 0; j < i; j++)
        {
            lSum += arr[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            rSum += arr[j];
        }
        if (lSum == rSum)
            return true;
    }
    return false;
}
int main()
{
    int arr[] = {11, 4, 8, -9, 20, 6};
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