//  Here we have used vector of vector to represent it as 2D array
// and we can even do it with single vector arrya
#include <iostream>
#include <vector>
using namespace std;
void print2Dvector(vector<vector<int>> arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m = 3, n = 2;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(i);
        }
        arr.push_back(v);
    }
    print2Dvector(arr, m, n);

    return 0;
}