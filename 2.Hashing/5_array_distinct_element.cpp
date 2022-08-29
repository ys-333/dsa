#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int arr[] = {15, 12, 13, 12, 13, 13, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    // see the qustion demand to find out the unique element in the array
    unordered_set<int> u;
    for (int i = 0; i < n; i++)
    {
        u.insert(arr[i]);
    }
    cout << "The unique element in the array are " << u.size() << endl;
    return 0;
}