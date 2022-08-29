// Revese a String

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void reverse(string s, int index)
{
    if (index == s.size())
    {
        return;
    }
    reverse(s, index + 1);
    cout << s[index];
}

int main()
{
    string s = "geeks for geeks";
    reverse(s, 0);

    return 0;
}