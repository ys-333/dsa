
// An element is leader in array if all element to  its right are smaller than it

#include <iostream>
using namespace std;
void leaderArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{
    int arr[] = {7, 10, 4, 3, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    leaderArray(arr, n);
    // printArray(arr,n) ;

    return 0;
}