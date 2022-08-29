/*
    Problem Statement: Given two string, check if they are rotaion of each other

    Input:  s1 =  "ABCD"
            s2 = "CDAB"
    Output: Yes
    Input:  txt = "ABAA"
            pat = "AAAB"
    Output: Yes
    Input:  txt = "ABAB"
            pat = "ABBA"
    Output: No

*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int isRotation(string s1, string s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = s1[0];
        for (int i = 0; i < n - 1; i++)
        {
            s1[i] = s1[i + 1];
        }
        s1[n - 1] = c;
        if (s1 == s2)
        {
            return true;
        }
        cout << " s1 " << s1 << " s2 " << s2 << endl;
    }
    return false;
}

int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";
    int n1 = s1.size();
    int n2 = s2.size();
    // swap(s1[0],s1[3]) ;
    cout << isRotation(s1, s2, s1.size());
    return 0;
}