/*
    Problem Statemnent: Convert infix expression to postfix
    Input: a+b/c
    Output: abc/+
*/

/*
    Approach.
    1. We will always print or append  the operand in given string.
    2. If stack is empty then push the operator in stack.
    3. If encounter opening parenthesis then push into stak
    4. If encounter closing parenthesis then pop all operator from stack until opening parenthesis is found.
    5.Then pop out the opening parenthesis also.
    6.If outside operator is of larger precedence compare to stack top then push into stack.
    7.Otherwise pop the element from stack until stack is empty or precedence of outside operator is larger or higher precedence than inside operator.
    8. At last if stack is not empty then pop out all operator and apppend it in the given output string.
    9. If its empty then return the output string.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// to return the precedence value of operator inside the stack

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
    case '(':
        return 0;
        break;

    default:
        break;
    }
}
int outPrec(char c)
{
    int res = -1;
    switch (c)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;
    case '^':
        return 5;
    case '(':
        return 7;

    default:
        break;
    }
    return -1;
}

// To return the precedence value of operator outside the stack

// Postfix function

void postfix(string str)
{
    string output = "";
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        // to check that wether str is operator or operand,if its operand than append to output string
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
        {
            output += str[i];
            cout << output << " " << endl;
            cout << "check1" << endl;
        }
        else
        {
            if (s.empty() || str[i] == '(' || outPrec(str[i]) > inPrec(s.top()))
            {
                s.push(str[i]);
                cout << "check2" << endl;
            }
            else if (str[i] == ')')
            {
                // So if we enocounter an closing parentheses then we pop until we found a opening parenthesis
                cout << "check3" << endl;
                while (s.top() != '(')
                {
                    output += s.top();
                    s.pop();
                }
                cout << "check4" << endl;
                if (s.empty())
                {
                    cout << "wrong input provided" << endl;
                    return;
                }
                cout << "check5" << endl;
                // other wise remove the opening parenthesis
                s.pop();
            }
            else
            {
                // if operand has low precedence than stack top
                cout << "check6" << endl;
                while (s.empty() == false && outPrec(str[i]) < inPrec(s.top()))
                {
                    output += s.top();
                    cout << output << endl;
                    s.pop();
                }
                cout << output << endl;
                cout << "check7" << endl;
                s.push(str[i]);
            }
        }
    }
    // to check wther stack is empty or nto
    if (!s.empty())
    {
        cout << "check8" << endl;
        while (!s.empty())
        {
            /* code */
            output += s.top();
            s.pop();
        }
    }
    cout << output << " ";
}

int main()
{
    string str = "a+b/c-d*e";
    postfix(str);
    // cout << output << endl;
    return 0;
}
