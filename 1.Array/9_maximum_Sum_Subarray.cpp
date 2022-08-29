#include <bits/stdc++.h>
using namespace std;

int subarraySum(int arr[], int n)
{
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            res = max(res, sum);
        }
    }
    return res;
}

int main()
{
    int arr[] = {5, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subarraySum(arr, n) << endl;
    return 0;
}