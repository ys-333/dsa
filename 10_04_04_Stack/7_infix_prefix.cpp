/*
    Problem Statement: Convert Infix to Prefix Expression
    Input: x+y*z
    Output: +x*yz
    Input: (x+y)*z
    Output: *+xyz
    Input: x+y*(z-w)
    Output: +x*y-zw
*/

/*
    Approach: Everythning same but just traverse the
    string from back and whenever ecounter an operand
    append it to fron of output string instead of doing it at back
*/
#include <iostream>
#include <stack>
using namespace std;

// See Will always have precedence of output operator lower as compare to
// operator inside stack even of same precedence

int inPrec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '^':
        return 6;
        break;
    case ')':
        return 0;

    default:
        break;
    }
    // to handle that tail error so return anyvalue
    return -1;
}
int outPrec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '^':
        return 5;
        break;
    case ')':
        return 100;

    default:
        break;
    }
    return -1;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ')';
}

string prefix(string s, int n)
{
    stack<char> st;
    string output = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122)
        {
            output = s[i] + output;
        }
        else
        {
            if (st.empty() || outPrec(s[i]) > inPrec(st.top()))
            {
                st.push(s[i]);
            }

            else if (s[i] == '(')
            {

                while (st.empty() == false && st.top() != ')')
                {
                    output = st.top() + output;
                    st.pop();
                }

                if (st.empty())
                {
                    return "Wrong Expresssion";
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                // this case handle if my output element has lower precedence than st.top()

                cout << st.top() << endl;
                cout << s[i] << endl;
                while (st.empty() == false && outPrec(s[i]) < inPrec(st.top()))
                {
                    output = st.top() + output;
                    st.pop();
                }

                st.push(s[i]);
            }
        }
    }
    if (st.empty() == false)
    {
        while (st.empty() == false)
        {
            output = st.top() + output;
            st.pop();
        }
    }
    return output;
}
int main()
{
    string s = "x+y*(z-w)";
    int n = s.size();
    string output = prefix(s, n);
    cout << output << endl;
    return 0;
}