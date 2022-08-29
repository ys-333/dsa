/*
    To find peak element in array in O(logn) time complexity
    Input:
    arr[] = {5,30,20,15,7}
    Output-> Index=2 that is elemnet 30
*/
#include <iostream>
using namespace std;
int peakElement(int arr[], int n, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << " low " << low << " high " << high << " mid " << mid << endl;
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
            {
                return arr[mid];
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
            {
                return arr[mid];
            }
            else
            {
                high = mid - 1;
            }
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid - 1] > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    // int arr[] = {5, 10, 70, 100, 200, 15, 7};
    int arr[] = {30, 12, 4, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = peakElement(arr, n, 0, n - 1);
    cout << res << endl;
    return 0;
}