#include <iostream>
using namespace std;
// to merge the sorted element from both recursion stack
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    // temporary element
    int temp1[n1];
    int temp2[n2];
    // copying element from main array to temp1 and temp2
    int k = 0;
    for (int i = 0; i <= mid; i++)
    {
        temp1[k] = arr[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        temp2[] = arr[i];
        k++;
    }

    // now to merge both temp array to main array
    int i = 0, j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }
    // now lets check weather any element is left in both array
    while (i < n1)
    {
        arr[k] = temp1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = temp2[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    int arr[] = {15, 2, 1, 12, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}