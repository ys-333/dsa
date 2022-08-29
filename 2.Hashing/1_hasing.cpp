/*
    1.Here user will ask whether particular alphabet exist in the array or not,if it does then return true
    other wise false.
*/

#include <bits/stdc++.h>
using namespace std;
bool searchChar(int temp[], char search)
{
    int index = int(search);
    if (temp[index - 97] == 1)
        return true;
    return false;
}
int main()
{
    string name = "yashwant";
    int n = name.length();
    int temp[26] = {0};
    for (int i = 0; i < n; i++)
    {
        int index = int(name[i]);
        temp[index - 97] = 1;
    }
    char search;
    cout << "Enter the character to be searched " << endl;
    cin >> search;
    bool res = searchChar(temp, search);
    if (res)
        cout << "Exist" << endl;
    else
        cout << "Do not exist" << endl;
}