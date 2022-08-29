#include <iostream>
using namespace std;

int subArrayEvenOdd(int arr[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 == 0 && arr[i - 1] % 2 != 0)
        {
            count++;
        }
        else if (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)
        {
            count++;
        }
        else
        {
            count = 1;
        }
    }
    return count;
}

int main()
{
    int arr[] = {10, 12, 14, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = subArrayEvenOdd(arr, n);
    cout << count << endl;
    return 0;
}