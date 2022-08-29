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
    unordered_map<int, int> u;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] == 0) ? -1 : 1;
    }
    int sum = 0;
    int prefixSum = 0;
    int res = 0;
    int end_index = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
        {
            res = max(res, i + 1);
            end_index = i;
        }
        if (u.find(prefixSum - sum) != u.end())
        {
            res = max(res, i);
        }
        u.insert({prefixSum, i});
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