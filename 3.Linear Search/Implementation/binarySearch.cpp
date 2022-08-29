#include <iostream>
using namespace std;
int binaryIndex(int arr[], int start, int end, int key)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = start + 1;
        }
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