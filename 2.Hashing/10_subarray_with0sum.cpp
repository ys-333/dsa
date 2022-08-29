/*
    arr[] = {1,3,13,-3,-10,5} ;

    Output ->yes
    Explanation-----> subarray(2,4) sum will give 0
*/

#include <iostream>
#include <unordered_set>
using namespace std;

bool subarraySum(int arr[], int n)
{
    // so here will use prefix sum array and hashing
    unordered_set<int> prefixSum;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (prefixSum.find(sum) != prefixSum.end() || sum == 0)
        {
            return true;
        }
        prefixSum.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 13, -3, -10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = subarraySum(arr, n);
    if (res)
        cout << "true";
    else
        cout << "false" << endl;
    return 0;
}