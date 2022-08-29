/*
    arr[] = {3,8,4,5,7}
    output = 3 as 3,4,5 are consecutive in this array
*/
#include <iostream>
#include <unordered_set>
using namespace std;
int count(int arr[], int n)
{
    unordered_set<int> s;
    int res = 1;
    int curr = 1;

    // insert all the element from the array into hash table
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            curr = 1;
            while (s.count(arr[i] + curr))
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}
int main()
{
    int arr[] = {3, 8, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count(arr, n);
    cout << res << endl;
    return 0;
}