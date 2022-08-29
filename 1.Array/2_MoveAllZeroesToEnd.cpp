/*
    Problem statement
    We have to move all zeroes to end and have maintain order of non zero element
    Input:
    arr[] = {0,1,0,2,3,0,0,5}
    Output-> [1,2,3,5,0,0,0,0]
*/


#include <iostream>
using namespace std;

void moveAllZeroToEnd(int arr[], int n)
{
    // We have to move all zeroes to end such that we have to maintain the order of elements as it is.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {0, 0, 0, 0, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveAllZeroToEnd(arr, n);
    printArray(arr, n);

    return 0;
}