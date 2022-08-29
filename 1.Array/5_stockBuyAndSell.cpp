#include <bits/stdc++.h>
using namespace std;

int stockBuySell(int arr[], int n)
{
    // first we need to find that when we sell stock
    int res = 0;
    int profit = 0;
    int net_profit = INT_MIN;
    int j, k = 0, selling_day;
    int buying_day;
    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        // for selling stock
        flag = 1;
        net_profit = INT_MIN;
        cout << "i" << i << endl;
        i = k;

        for (j = i + 1; j < n; j++)
        {
            profit = arr[j] - arr[i];
            if (profit > net_profit)
            {
                net_profit = profit;
            }
            else
            {
                selling_day = j;
                flag = 0;
                break;
            }
        }
        cout << "net profit" << net_profit << endl;
        res += net_profit;
        cout << "res trading " << res << endl;
        if (flag == 1)
            break;
        if (selling_day == n - 1)
            break;
        // cout << net_profit<<endl ;

        for (k = selling_day; k < n - 2; k++)
        {
            if (arr[k] < arr[k + 1])
            {
                break;
            }
        }
        cout << "i " << i << endl;
        cout << "net profit " << net_profit << endl;
        cout << "Selling day " << selling_day << endl;
        cout << "**********************************" << endl;
    }
    if (res < 0)
        return 0;
    return res;
}

int main()
{
    int arr[] = {30, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int netProfit = stockBuySell(arr, n);
    cout << "The resultant profit is as follow " << netProfit << endl;
    return 0;
}