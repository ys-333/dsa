#include <iostream>
#include <vector>
using namespace std;

// print 2 vector

void print2Dvector(vector<int> v[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m = 3, n = 2;
    vector<int> arr[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i].push_back(i);
        }
    }
}