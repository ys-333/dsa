/*
    Problem Statement: To check for balances Parenthesis
    Input: [({})]
    Output:True
    Input: [({})])
    Output: False
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//  to match the char that is opening and closing

bool matchchar(char a, char b)
{
    return a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']';
}

bool check(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        // only to push the opening brackets
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            // if the first char of string is closing brackets
            if (s.empty())
            {
                return false;
            }
            else if (matchchar(s.top(), str[i]) == false)
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty() == true);
}
int main()
{
    string str = "[({})]";
    check(str) == true ? cout << "Balanced Parenthesis" : cout << "Not a balanced parenthesis";
    return 0;
}