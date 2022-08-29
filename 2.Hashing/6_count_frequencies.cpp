/*
    To count frequency of element in the array
    [10,10,12,13,14,13,14]
    Output- >   10 2
                12 1
                13 2
                14 2
*/
#include <iostream>
#include <unordered_map>
using namespace std;

void printMap(unordered_map<int, int> ump)
{
    for (auto it : ump)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    int arr[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }
    printMap(ump);
    return 0;
}