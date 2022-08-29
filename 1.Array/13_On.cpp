#include <iostream>
using namespace std;

void printGroups(int arr[], int n)
{
    /*
        Testcase: [0, 0, 1, 1, 0, 0, 1, 1, 0],[0,0,1,1]

        1.As in array a[0] = 1 and a[n-1] = 1, so in such binary array where first and last element are same,
        either 0 or 1 will lead the group in array whoever is at first and last index
        2.If a[0] = 0 and a[n-1] = 1 or vice-versa, then both will have same group
    */
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
            {
                cout << "from " << i << " to ";
            }
            else
            {
                cout << i - 1 << endl;
            }
        }
    }

    if (arr[n - 1] != arr[0])
    {
        cout << n - 1 << endl;
    }
}

int main()
{
    int arr[] = {0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printGroups(arr, n);
    return 0;
}