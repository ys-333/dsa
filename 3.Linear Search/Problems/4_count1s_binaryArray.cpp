/*
    To find count of 1's in binary array
    Input:
    arr[] = {0,0,0,0,1,1,1,1}
    Output:4

    Input:
    arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
    Output:4
*/
#include <iostream>
using namespace std;
int count1(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            if (arr[mid + 1] == key)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count1(arr, 0, n - 1, 0);
    cout << n - res - 1 << endl;
    return 0;
}