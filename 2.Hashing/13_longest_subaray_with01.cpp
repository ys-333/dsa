/*
    Input
    arr[] = {1,0,1,1,0,1,0,1}
    Output = 6
    Explanation - - > The sub-array which contain equal number of zeroes and one's
*/
#include <bits/stdc++.h>
using namespace std;
int count(int arr[], int n)
{
    int res = 0;
    int j;
    for (int i = 0; i < n; i++)
    {
        int count1 = 0, count0 = 0;
        for (j = i; j < n; j++)
        {
            if (arr[j] == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }
            if (count1 == count0)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count(arr, n);
    cout << res << endl;
    return 0;
}