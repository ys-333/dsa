/*

Problem statement:Search in Sorted Relatead Array

 Input:
 arr[]= {10,20,30,40,50,8,9}
 Key=30
 Output = 2
 *******************
 arr[]={100,200,300,10,20}
 Key=40
 Output=-1
*/
#include <iostream>
using namespace std;
int index(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > arr[low])
        {
            if (key > arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = index(arr, 0, n - 1, 30);
    cout << res << endl;
    return 0;
}
