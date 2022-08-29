// TO FIND SUM OF SUBARRAY IN CIRCULAR ARRAY
#include <bits/stdc++.h>
using namespace std;

int subArraysum(int arr[], int n)
{
    // Algorithm to find out maximum subarray of circular array
    /*
         1.To find out the maximum sum in normal array using kadane's algorithm
         2.To find out the maximum sum in circular array using modified kadane's algorithm
             -> So here we find out subarray with minimum sum and subtract it from the total sum of subarrray ;
         3.Then we find out the maximum of both normal and circular array sum.
    */

    int sum = 0;
    int resNormal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < arr[i])
        {
            sum = arr[i];
        }
        resNormal = max(sum, resNormal);
    }

    sum = 0;
    int totalSum = 0;
    int minSubarray = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        sum += arr[i];

        if (sum > arr[i])
        {
            sum = arr[i];
        }

        minSubarray = min(minSubarray, sum);
    }

    int resCircular = (totalSum) - (minSubarray);

    int res = max(resCircular, resNormal);

    return res;
}

int main()
{
    int arr[] = {3, -4, 5, 6, -8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = subArraysum(arr, n);
    cout << res << endl;
    return 0;
}