/*
    Title: Print a Matrix in Snake pattern
    Input: 1 2 3 4
           5 6 7 8
           9 10 11 12
           13 14 15 16

    output:1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13

*/

#include <iostream>
using namespace std;
int main()
{
    int m = 4, n = 4;
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

// hard coded approach

/*int i = 0, j = 0;
    while (i < m)
    {
        cout << arr[i][j] << " ";
        if (j == n)
        {
            j--, i++;
        }
        if (j == -1)
        {
            j++, i++;
        }
        j++;
    }
    */