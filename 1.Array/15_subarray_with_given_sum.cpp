/*
    1.[1,4,20,3,10,5] so here we have to find sum = 33 in the array.
    ==> Given a sorted array of non-negative integer.Find if there is a subarray with given sum
*/

#include <bits/stdc++.h>
using namespace std;

bool subArraySum(int arr[], int n, int sum)
{
    int curr_sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        while (curr_sum > sum)
        {
            curr_sum -= arr[j];
            j++;
        }
        if (curr_sum == sum)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 330;
    bool res = subArraySum(arr, n, sum);
    if (res)
    {
        cout << "Exist" << endl;
    }
    else
    {
        cout << "not exist" << endl;
    }
    return 0;
}