#include <iostream>
using namespace std;

int majorityVoting(int arr[], int n)
{
    /*
        1.We find the majority element in array using moores's voting algorithm
        2.The first part of moore's voting algorithm ensure that or find out the maxium element in array
        3.The second part make sure that element is greatere than n/2 of array where n is size of array
    */

    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
    }
    if (count <= n / 2)
        return -1;
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = majorityVoting(arr, n);
    cout << res << endl;
    return 0;
}