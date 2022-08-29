/*
    Problem Statement: Evaluate Postfix Expression
    Input:10 2 * 3 5 * + 9 -
    Output:26
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> cal(stack<int> s, char c)
{
    int a = s.top();
    s.pop();
    int b = s.top();
    // cout<<" a "<<a<<" "<<c<<" b "<<b<<endl;
    s.pop();
    int res;
    if (c == '*')
    {
        res = a * b;
    }
    if (c == '/')
    {
        res;
        if (a > b)
        {
            res = a / b;
        }
        else
        {
            res = b / a;
        }
    }
    if (c == '+')
    {
        res = a + b;
        cout << res << " add";
    }
    if (c == '-')
    {
        res = abs(a - b);
    }
    if (c == '^')
    {
        res = pow(a, b);
    }
    s.push(res);
    return s;
}
bool matchOperator(char c)
{
    return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
}
int main()
{
    string input = "10 2 3 * 2 / +";
    string num = "";

    stack<int> s;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ' && matchOperator(input[i - 1]) == false && matchOperator(input[i]) == false)
        {
            cout << num << endl;
            num += input[i];
        }
        else if (input[i] == ' ' && matchOperator(input[i - 1]) == false)
        {
            // here we covert num to int and then push to stack
            cout << " num " << num << endl;
            stringstream geek(num);
            int x = 0;
            geek >> x;
            s.push(x);
            num = "";
        }
        if (matchOperator(input[i]))
        {
            s = cal(s, input[i]);
        }
    }
    cout << s.top();
}