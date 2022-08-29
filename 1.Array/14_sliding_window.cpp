/*
    Using sliding window technique find the sum maximum sum upto k element
    TestCase: [1,8,30,-5,20,7]
*/

#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n, int k)
{
    int sum = 0;
    int res = INT_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        res = max(res, sum);
    }
    return res;
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