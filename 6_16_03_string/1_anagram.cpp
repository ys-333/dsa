/*
    Problem Statement: Given Two string check if they are anagram of each other
    Input:
        s1="geeks", s2="ekegs"
    Output: Yes
*/

#include <iostream>
#include <string>
using namespace std;
// anagram function
bool anagram(string s1, string s2)
{
    int temp[256] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        // int index = (int)s1[i];
        // temp[index]++;
        temp[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++)
    {

        temp[s2[i]]--;
    }
    // traversal of temp array and if we find any non-zero element in the array that means the string are not anagram of each other
    for (int i = 0; i < 256; i++)
    {
        if (temp[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s1 = "geks";
    string s2 = "ekegs";
    bool res = anagram(s1, s2);
    if (res)
    {
        cout << "anagram of each other" << endl;
    }
    else
    {
        cout << "they are not anagram of each other" << endl;
    }
    return 0;
}