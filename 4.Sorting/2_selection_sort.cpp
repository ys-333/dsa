#include <iostream>
#include <climits>
using namespace std;
void selectionSort(int arr[], int n)
{
    int minE;
    int pos;
    for (int i = 0; i < n - 1; i++)
    {
        minE = arr[i];
        pos = i;
        int j = i + 1;
        while (j < n)
        {
            if (minE > arr[j])
            {
                minE = arr[j];
                pos = j;
            }
            j++;
        }
        swap(arr[i], arr[pos]);
    }
}
// void printArray(int arr[], int n)
// {
//     for (auto x : arr)
//     {
//         cout << x << " ";
//     }
// }
int main()
{
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}