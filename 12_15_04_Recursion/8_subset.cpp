/*
    Problem Statement: Print Subset of string
*/
#include <iostream>
using namespace std;
void subset(string str, string curr, int index)
{
    if (index == str.size())
    {
        cout << curr << " ";
        return;
    }
    subset(str, curr, index + 1);
    subset(str, curr + str[index], index + 1);
}
int main()
{
    string str = "ABC";
    subset(str, "", 0);
}