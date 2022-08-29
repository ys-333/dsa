/*
    print Matrix in spirla order

    Input:
        arr[R][C] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
    Ouput: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/
#include <bits/stdc++.h>
using namespace std;
// declare const R and C
const int R = 4;
const int C = 4;

// to print matrix
void printMatrix(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// rotateMatrix
void spiral(int arr[R][C])
{
    // top - >top row right->right coloumn bottom->bottom row
    // left ->left column
    int top = 0, right = C - 1, bottom = R - 1, left = 0;
    while (top <= bottom || left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            cout << arr[bottom][i] << " ";
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            cout << arr[i][left] << " ";
        }
        left++;
    }
}
int main()
{
    int arr[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}

    };
    spiral(arr);
    // printMatrix(arr);
}
