/*
    Input: arr[] = [2,3,-8,7,-1,2,3]
    Output:11
    Explanation:  sub-array from index 3 to 6 have maximum sum
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(int arr[], int n)
{
    int sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // if -> it check that all sum upto i-1 if smaller than arr[i] than we update current sum to arr[i]
        if (sum < arr[i])
        {
            sum = arr[i];
        }
        res = max(res, sum);
    }

    return res;
}

int main()
{
    int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subarraySum(arr, n) << endl;
    return 0;
}