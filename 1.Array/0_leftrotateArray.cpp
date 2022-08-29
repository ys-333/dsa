#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low, int high)
{
    while (low <= high)
    {
        swap(arr[low], arr[high]);
        low++,
            high--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    // this solution is done with concept that
    // to rotate element by d on leftside first reverse the 0 to d-1 elements
    // then the rest of element that is from d to n-1

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
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
    // to left rotate array in O(n) time and with O(1) space complexity

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d;
    cout << "Enter the value of rotation by D" << endl;
    cin >> d;
    leftRotate(arr, n, d);
    printArray(arr, n);
    return 0;
}