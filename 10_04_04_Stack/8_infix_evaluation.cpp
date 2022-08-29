/*
    Problem Statement: Evaluate prefix expression
    Input: "+ * 10 2 3"
    Output: 23
    Input: "* + 10 2 3"
    Output: 36
*/
// #include <iostream>
// #include <stack>
// #include <sstream> //stringstream
// #include <math.h>
#include <bits/stdc++.h>
using namespace std;

stack<int> cal(stack<int> s, char c)
{
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    int res;
    switch (c)
    {
    case '+':
        /* code */
        res = a + b;
        break;

    case '-':
        /* code */
        res = a - b;
        break;

    case '*':
        /* code */
        res = a * b;
        break;

    case '/':
        /* code */
        res = a / b;
        break;

    case '^':
        /* code */
        res = pow(a, b);
        break;

    default:
        break;
    }
    s.push(res);
    return s;
}

// to check if char is operator or not
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}
int prefix(string str)
{

    stack<int> s;
    string num = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        // "+ * 10 2 3";
        // this ensure that only integer operand get added to num string
        if (str[i] != ' ' && isOperator(str[i]) == false)
        {

            num = str[i] + num;
        }
        else if (str[i] == ' ' && isOperator(str[i + 1]) == false) // this push only into stack if blank  space is encounter
        {
            //  i  need to convert num string into an integer value

            int x = 0;
            stringstream geek(num);
            geek >> x;
            s.push(x);
            // cout<<s.top()<<endl ;
            num = "";
        }
        else if (isOperator(str[i]))
        {

            s = cal(s, str[i]);
        }
    }
    return s.top();
}
int main()
{
    string str = "^ 10 ^ 2 3";
    int val = prefix(str);
    cout << val << endl;
    return 0;
}