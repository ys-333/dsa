/*
    Array -> [1,0,0,0,1,0,0,1,1,1] || [1,1,1]
    This is given binary array, and here are 3 group of  1's and 2 groups of 0's
    You need to flip the minimum group and print the index from start to end of that minium group to be flip

    Output - >  0 index to 2 and 5 to 6 (as here 0 is the minimum group)

*/

#include <iostream>
using namespace std;

void flipGroup(int arr[], int n)
{
    int g1 = 0, g0 = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == 1 && arr[i] == 0)
        {
            g1++;
        }
        if (arr[i - 1] == 0 && arr[i] == 1)
        {
            g0++;
        }
    }
    if (arr[n - 1] == 1)
    {
        g1++;
    }
    else
        g0++;

    if (g1 == 0 || g0 == 0)
    {
        cout << "The array either contain zero or 1 fully " << endl;
        return;
    }

    int elementToBeFlipped = 0;
    if (g1 < g0)
    {
        elementToBeFlipped = 1;
    }
    else
    {
        elementToBeFlipped = 0;
    }

    // to print start and end index of minimum group element
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elementToBeFlipped && arr[i - 1] != elementToBeFlipped)
        {
            start = i;
        }
        if (arr[i] == elementToBeFlipped && arr[i + 1] != elementToBeFlipped)
        {
            end = i;
            cout << " Start " << start << " End " << end << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    flipGroup(arr, n);
    return 0;
}