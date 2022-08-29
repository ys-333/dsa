#include <iostream>
using namespace std;

// To move all zero element to end

void moveAllZeroToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }
    while (count < n)
    {
        arr[count++] = 0;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 5, 0, 0, 8, 0, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveAllZeroToEnd(arr, n);
    printArray(arr, n);
    return 0;
}