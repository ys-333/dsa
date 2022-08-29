/*
    Problem Statement: Given a text string and pattern string, find if permutation of the pattern exist in the text string
    Input:  txt =  "geeksforgeeks"
            pat = "egek"
    Output: Yes
    Input:  txt = "geeksforgeeks"
            pat = "gks"
    Output: No
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int textAndPattern(string text, string pat, int n, int patL)
{
    int countText = 0;
    int countPat = 0;
    for (int i = 0; i < patL; i++)
    {
        countText += text[i];
        countPat += pat[i];
    }
    if (countText == countPat)
        return true;
    for (int i = 0; i <= n - patL; i++)
    {
        countText = countText - text[i] + text[i + patL];
        if (countText == countPat)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string text = "geeksforgeeks";
    string pat = "egek";
    int n = text.size();
    int patL = pat.size();
    bool res = textAndPattern(text, pat, n, patL);
    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}