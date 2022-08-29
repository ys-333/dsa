// TO FIND SUM OF SUBARRAY IN CIRCULAR ARRAY
#include <bits/stdc++.h>
using namespace std;

int subArraysum(int arr[], int n)
{
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];

        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }

        res = max(res, curr_max);
    }

    return res;
}

int main()
{
    int arr[] = {5, -2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = subArraysum(arr, n);
    cout << res << endl;
    return 0;
}