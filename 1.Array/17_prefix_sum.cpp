#include <iostream>
using namespace std;
int temp[] = {0};

int prefixSum(int arr[], int n, int l, int r)
{
    /*int res = temp[r];
    for (int i = 0; i < l; i++)
    {
        res -= arr[i];
    }
    */
    if (l == 0)
        return temp[r];
    return temp[r] - temp[l - 1];
}

void printArray(int temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}
int main()
{
    int arr[] = {2, 8, 3, 9, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    temp[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        temp[i] = sum;
    }
    // printArray(temp, n);
    int res = prefixSum(arr, n, 2, 6);
    cout << res << endl;
    return 0;
}