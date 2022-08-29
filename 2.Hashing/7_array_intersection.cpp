/*
    a[] = {10,15,20,15,30,30,5}
    b[] = {30,5,30,80}
    Output - > 2

    a[] = {10,10,10}
    b[] = {10,10,10}
    Output - > 1

    Explanation later
*/

#include <iostream>
using namespace std;
int countCommonDistinctElement(int a[], int b[], int n, int m)
{
    bool visited[m] = {false};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
            {
                    count++;
               for (int j = 0; j < m; j++)
        {
            if (b[j] == a[i])
            {
                if (visited[j] == false)
                 visited[j] = true;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return count;
}

int main()
{
    int a[] = {10, 10, 10};
    int b[] = {10, 10, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int count = countCommonDistinctElement(a, b, n, m);
    cout << count << endl;
    return 0;
}