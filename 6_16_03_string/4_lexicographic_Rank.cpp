/*
    Problem Statement: Given strig find lexicographic rank of it
    Input: "BAC"
    Output: 3
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int lexicographicRank(string str, int n)
{
    int count[256] = {0};
    int fact = factorial(n);
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    // to create cumalative sum to find alphabet smaller than it
    for (int i = 1; i < 256; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    // create rank
    int rank = 0;
    for (int i = 0; i < n; i++)
    {
        fact = fact / (n - i);
        rank += count[str[i] - 1] * fact;
        // now as i have fixed ith character and we need to search smaller alphabet only at right side
        for (int j = str[i]; j < 256; j++)
        {
            count[j]--;
        }
    }
    return rank + 1;
}
int main()
{
    string str = "ABC";
    int n = str.size();
    cout << lexicographicRank(str, n);

    return 0;
}

// O(N*2) approach
// int res = 0;
// for (int i = 0; i < n; i++)
// {
//     int count = 0;
//     for (int j = i + 1; j < n; j++)
//     {
//         if (str[i] > str[j])
//             count++;
//     }
//     int fact = factorial(n - i - 1);
//     res += count * fact;
// }
// return res + 1;