#include <bits/stdc++.h>
using namespace std;
vector<int> leader(int arr[], int n)
{
    int maxElement = INT_MIN;
    vector<int> leaderArray;
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxElement < arr[i])
        {
            leaderArray.push_back(arr[i]);
            maxElement = arr[i];
        }
    }
    return leaderArray;
}

void printVector(vector<int> leaderArray)
{
    for (int i = leaderArray.size() - 1; i >= 0; i--)
    {
        cout << leaderArray[i] << " ";
    }
}

int main()
{
    int arr[] = {30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> leaderArray;
    leaderArray = leader(arr, n);
    printVector(leaderArray);
    return 0;
}