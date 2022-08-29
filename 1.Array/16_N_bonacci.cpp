#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 4, m = 10;
    int arr[m];
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            arr[i] = 1;
        else
        {
            arr[i] = 0;
        }
    }
    int sum = 1;
    arr[n] = sum;
    int i = 0, j = n;
    int count = n + 1;
    while (count < m)
    {
        sum = sum - arr[i] + arr[j];
        arr[i + n + 1] = sum;
        i++, j++, count++;
    }
    printArray(arr, m);
    return 0;
}