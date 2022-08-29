/*
    Input:
    arr[] = {2,3,4,8,9,20,40}
    X=32
    Output: True
    Explanation: arr[2]+arr[3]+arr[6]
*/
#include <iostream>
using namespace std;
bool isTriplet(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == x)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = isTriplet(arr, n, 3);
    cout << res << endl;
    return 0;
}