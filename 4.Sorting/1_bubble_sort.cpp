#include <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(int arr[], int n)
{
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {11, 1, 0, 2, 25, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr + n);
    bubbleSort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}