#include <iostream>
using namespace std;
// to merge the sorted element from both recursion stack
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    // temporary element
    int L[n1];
    int R[n2];
    // copying element from main array to L and R
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[j + mid + 1];
    }

    // now to merge both temp array to main array
    int i = 0, j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    // now lets check weather any element is left in both array
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
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