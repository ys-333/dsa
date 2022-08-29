#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key)
{
    // So we are dicussing about linear search, that is used to search element in array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {5, 1, 20, 3, 2, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 190;
    int index = linearSearch(arr, n, key);
    cout << index << endl;
    return 0;
}