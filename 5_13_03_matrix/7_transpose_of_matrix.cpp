// Transpose of a Matrix
#include <bits/stdc++.h>
using namespace std;
// declare const R and C
const int R = 4;
const int C = 4;
void transposeMatrix(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
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

int main()
{
    int arr[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}

    };
    transposeMatrix(arr);
    printMatrix(arr);
}