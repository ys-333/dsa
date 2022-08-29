// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
using namespace std;
void printHash(unordered_map<int, int> s)
{

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}
int main()
{
    unordered_map<int, int> s;
    // int arr[] = {10, 10, 10, 10};
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    for (int i = 0; i < k; i++)
    {
        s[arr[i]]++;
    }
    cout << s.size() << " ";
    for (int i = k; i < n; i++)
    {
        s[arr[i - k]]--;
        if (s[arr[i - k]] == 0)
        {
            s.erase(arr[i - k]);
        }
        s[arr[i]]++;
        cout << s.size() << " ";
    }

    return 0;
}