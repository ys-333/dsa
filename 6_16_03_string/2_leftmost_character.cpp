/*
    Problem Statement:Given a String, find the left most charater that repeats
    str = "geeksforgeeks"
    O/P = 0
    str = "abbcc"
    o/p = 1
    str = "abc"
    op  -1
*/
#include <iostream>
#include <climits>
#include <string>
using namespace std;
// that's our function implementation
int indexOfLeftmostChar(string str, int n)
{
    int temp[256];
    for (int i = 0; i < 256; i++)
    {
        temp[i] = -1;
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (temp[str[i]] == -1)
        {
            temp[str[i]] = i;
        }
        else
        {
            res = min(res, temp[str[i]]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string str = "abcdd";
    int n = str.size();
    cout << indexOfLeftmostChar(str, n);
}

// O(n^2) Solution
//  for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (str[i] == str[j])
//             {
//                 return i;
//             }
//         }
//     }
//     return -1;

// **********************************

// Time compexity -> O(n+alphabet)
// space complexity -> O(alphabet)
/*int temp[256] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[str[i]]++;
    }
    // now i typecast string to integer then search at that index and see that weather its repeatitive or not
    for (int i = 0; str.size(); i++)
    {
        int index = (char)str[i];
        if (temp[index] > 1)
        {
            return i;
        }
    }
    return false;
*/