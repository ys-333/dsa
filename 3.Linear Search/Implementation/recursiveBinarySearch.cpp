/*
    To search element using binary search first pre-requisite is
    1) Array must be sorted
*/
#include <iostream>
using namespace std;
int binaryIndex(int arr[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binaryIndex(arr, start, mid - 1, key);
        else
            return binaryIndex(arr, mid + 1, end, key);
    }
    return -1;
}
int main()
{
    int arr[] = {10, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = binaryIndex(arr, 0, n - 1, 10);
    cout << res << endl;
    return 0;
}