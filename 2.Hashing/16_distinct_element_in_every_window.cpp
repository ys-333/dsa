/*
    Input
    arr[] = {10,20,20,10,30,40,10}
    k=4 (k is window size)
    O/p ---> 2 3 4 3
*/
#include <iostream>
using namespace std;
void distinctElement(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i <= n - k; i++)
    {
        count = 0;
        for (int j = i + k - 1; j >= i; j--)
        {
            int flag = 1;
            for (int k = j - 1; k >= i; k--)
            {
                if (arr[j] == arr[k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                count++;
            }
        }
        cout << count << " ";
    }
}
int main()
{
    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    distinctElement(arr, n, k);
    return 0;
}