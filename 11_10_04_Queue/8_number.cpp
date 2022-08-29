/*
    Problem Statement: Generate Number with given digits.
    Given a number n, print first n numbers in increasing order
    such tha tall such number have digits in set {5,6}
    Input: n=10;
    Output:5,6,55,56,65,66,555,556,565,566
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    So to handle large number we used number as string
    and queue data structure to store that string
*/
void generateNumber(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < n; i++)
    {
        string curr = q.front();
        cout << curr << " ";
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{
    int n = 10;
    generateNumber(n);
    return 0;
}

/*
// this works better when n is small as  there could be number that can not be stored in long int or long long int
vector<int> generateNumber(int n)
{
    vector<int> v;
    int count = 0;
    while (v.size() != 10)
    {
        count++;
        int num = count;
        int flag = 1;
        while (num != 0)
        {
            int rem = num % 10;
            if (rem != 5 && rem != 6)
            {
                flag = 0;
                break;
            }
            num /= 10;
        }
        if (flag == 1)
        {
            v.push_back(count);
        }
    }

    return v;
}

*/