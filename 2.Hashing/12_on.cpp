#include <iostream>
#include <unordered_map>
using namespace std;
int longestSubarray(int arr[], int n, int sum)
{
    unordered_map<int, int> u;
    int prefixSum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
        {
            int count = i - 0 + 1;
            res = max(res, count);
        }
        else if (u.find(prefixSum - sum) != u.end())
        {
            auto it = u.find(prefixSum - sum);
            int count = i - it->second;
            res = max(res, count);
        }
        else
            u.insert({prefixSum, i});
    }
    return res;
}
int main()
{
    int arr[] = {8, 3, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;
    int count = longestSubarray(arr, n, sum);
    cout << count << endl;
    return 0;
}