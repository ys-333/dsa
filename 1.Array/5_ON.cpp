#include <iostream>
using namespace std;

int maxProfit(int arr[], int n)
{

    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main()
{
    int arr[] = {30, 50, 10, 2, 1, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int profit = maxProfit(arr, n);
    cout << "The net profit in Stock Market is " << profit << endl;
    return 0;
}