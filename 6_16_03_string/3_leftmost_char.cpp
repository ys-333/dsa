/*
    Problem statement:Given a String, find the leftmost characte that does not repeat
    Input: "geeksforgeeks"
    Output: 5
    Input: "aabbcc"
    Output: -1
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int leftmostCharDoNotRepeat(string str, int n)
{
    int temp[256];
    for (int i = 0; i < 256; i++)
    {
        temp[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (temp[str[i]] == -1)
        {
            temp[str[i]] = i;
        }
        else
        {
            temp[str[i]] = -2;
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
    {
        if (temp[i] >= 0)
        {
            res = min(res, temp[i]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}
int main()
{
    string str = "abcdddebaace";
    int n = str.size();
    cout << leftmostCharDoNotRepeat(str, n);
    return 0;
}