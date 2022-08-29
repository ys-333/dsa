#include <iostream>
#include <unordered_map>
using namespace std;

int maxLength(int temp[], int n, int sum)
{
    unordered_map<int, int> u;
    int res = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += temp[i];
        if (prefixSum == sum)
        {
            res = max(res, i + 1);
        }
        else if (u.find(prefixSum - sum) != u.end())
        {
            auto it = u.find(prefixSum - sum);
            res = max(res, i - it->second);
        }
        else
            u.insert({prefixSum, i});
    }
    return res;
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    // here we will use temp array which is form by subtracting both the array
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }
    int res = maxLength(temp, n, 0);
    return 0;
}