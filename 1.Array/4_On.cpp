/*
    Input: arr[] = {30,20,10};
    Output: 20  arr[]
*/

#include <bits/stdc++.h>
using namespace std;

// to calculate maximum difference between array such that arr[j]-arr[i] is maximum and j>i ;

int maxDifference(int arr[], int n)
{
    // so baically here we simultaneously find out the smallest element in the array
    int res = arr[1] - arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxDifference(arr, n);
    cout << maxDiff << endl;
    return 0;
}