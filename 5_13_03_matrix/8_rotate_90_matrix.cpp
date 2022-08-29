/*
    Rotate a matrix
    Input:
        arr[R][C] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
    Ouput:
        [
            4,8,12,16
            3,7,11,15
            2,6,10,14
            1,5,8,13
        ]


        Hint-> first find the transpose of matrix and then reverse row of transposed matrix
*/
#include <bits/stdc++.h>
using namespace std;
// declare const R and C
const int R = 4;
const int C = 4;
// to find transpose of matrix
void transpose(int arr[R][C])
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
// rotateMatrix
void rotateMatrix(int arr[R][C])
{
    // transpose of matrix
    transpose(arr);
    // to reverse coloumn of matrix
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R / 2; j++)
        {
            swap(arr[j][i], arr[R - j - 1][i]);
        }
    }
    // print rotated matrix by angle of 90 degree
}
int main()
{
    int arr[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}

    };
    rotateMatrix(arr);
    // printMatrix(arr);
}

/*
    One of the way we can do it

     int temp[R][C] ;
    int  r=0,c=0 ;
    for (int i = C - 1; i >= 0; i--)
    {
        for (int j = 0; j < R; j++)
        {
            temp[r][c] = arr[j][i] ;
            c++ ;
        }
        if(c==C){
            r++ ;
            c=0 ;
        }
        cout << endl;
    }
*/