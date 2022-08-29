/*
    Input: arr[] = [0,1,1,0,1,0,0]
    Output: 2

    Input: arr[] = [1,0,1,1,1,1,0,1,1]
    Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

int count(int arr[], int n)
{
    int res = INT_MIN;
    int count = 0;
    int flag = 1; // this flag is basically to check that whether is all element 1 in array ;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            flag = 0;
            res = max(res, count);
            count = 0;
        }
    }
    if (flag == 1)
    {
        return count;
    }
    return res;
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count(arr, n);
    cout << res << endl;
    return 0;
}