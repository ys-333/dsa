#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j++;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}