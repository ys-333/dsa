/*
    So basically it's an unsorted array.And we need to find an pair in array that has sum equal to given sum.

    arr[] = {3,2,8,15,-8} ; Sum = 17 ;
    Output - > Yes        arr[1]+arr[3] = 17.

    arr[] = {5,8,-3,6}  Sum =3
    Outptu - > Yes   arr[2]+arr[3]


*/

#include <iostream>
#include <unordered_set>
using namespace std;

bool pairSum(int arr[], int n, int res)
{
    unordered_set<int> s;
    // for (int i = 0; i < n; i++)
    // {
    //     s.insert(arr[i]);
    // }
    // for (int i = 0; i < n; i++)  -------------> This would fail for arr[] ={11,5,6} and When Sum =10
    // {
    //     int key = res - arr[i];
    //     if (s.find(key) != s.end())
    //     {
    //         return true;
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        if (s.find(res - arr[i]) != s.end())
        {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    int arr[] = {11, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = 10;
    bool ans = pairSum(arr, n, res);
    if (ans)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}