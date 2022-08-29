/*
    Problem Statement: Write a Recursive function to print
    numbers from n to 1.
*/
#include <iostream>
#include <string>
using namespace std;
bool isCheck(string s, int low, int high)
{
    if (low >= high)
    {
        return true;
    }
    if (s[low] != s[high])
    {
        return false;
    }
    return isCheck(s, low + 1, high - 1);
}
int main()
{
    // string s1 = "geeks" ;
    string s1 = "aabaa";
    string s2 = "hannah";
    bool res1 = isCheck(s1, 0, s1.size() - 1);
    bool res2 = isCheck(s2, 0, s2.size() - 1);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}