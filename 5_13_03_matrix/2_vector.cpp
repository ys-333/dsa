/*
     we will make multidimensional array using vector<vector<int>> which is basically not cache
     friendly but here we can have flexible row and coloumn and we do not have to predefine
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m = 3;
    vector<vector<int>> array;
    // lets take input in this vector array
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < 2; j++)
        {
            v.push_back(i + j);
        }
        array.push_back(v);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}