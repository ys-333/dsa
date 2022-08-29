#include <bits/stdc++.h>
using namespace std;

// to calculate maximum difference between array such that arr[j]-arr[i] is maximum and j>i ;

int maxDifference(int arr[], int n)
{
    int maxDiff = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int diff = arr[i] - arr[j];
            if (maxDiff < diff)
            {
                maxDiff = diff;
            }
        }
    }
    return maxDiff;
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = maxDifference(arr, n);
    cout << maxDiff << endl;
    return 0;
}