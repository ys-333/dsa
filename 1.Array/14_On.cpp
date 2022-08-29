/*
    Using sliding window technique find the sum maximum sum upto k element
    TestCase: [1,8,30,-5,20,7]
*/

#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n, int k)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
        curr_sum += arr[i];
    }
    int max_sum = curr_sum;

    for (int i = 1; i <= n - k; i++)
    {
        curr_sum += arr[i + 2] - arr[i - 1];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    int res = sum(arr, n, k = 3);
    cout << res << endl;
    return 0;
}