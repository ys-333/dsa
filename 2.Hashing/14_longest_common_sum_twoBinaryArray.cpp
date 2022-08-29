/*
   Question - - > Longest common span with same sum in two binary array
   Input
        arr1[] = {0,1,0,0,0,0}
        arr2[] = {1,0,1,0,0,1}
    Output
        4
    Explantion
        As from same index 1 to 4 both array have same sum in subarray
*/

#include <iostream>
using namespace std;
int count(int arr1[], int arr2[], int n)
{
    int res = 0;
    int count = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = 0, sum2 = 0, count = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += arr1[j];
            sum2 += arr2[j];
            count++;
            if (sum1 == sum2)
            {
                res = max(res, count);
                // count = 0;
            }
        }
    }
    return res;
}
int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int res = count(arr1, arr2, n);
    cout << res << endl;
    return 0;
}