/*
    so basically we find pair sum using two pointer apporach
    two pointer approach can used only when array is sorted
    Input:
    arr[] = {2,5,8,12,30}
    X=17
    Output: True
    Input:
    arr[]={3,8,13,18}
    X=14
    Output: False
*/
#include <iostream>
using namespace std;
bool isPairSum(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == x)
        {
            return true;
        }
        else if (sum < x)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}
int main()
{
    int arr[] = {3, 8, 13, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = isPairSum(arr, n, 17);
    cout << res << endl;
    return 0;
}