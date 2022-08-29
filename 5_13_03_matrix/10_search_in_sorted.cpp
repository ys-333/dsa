/*
    Problem Statement:- Search in row and column wise sorted matrix
    Input:
    [
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    ]
    Key = 29
    Output: (2,1)
*/
#include <iostream>
using namespace std;
const int R = 4;
const int C = 4;
void search(int arr[R][C], int key)
{
    int r = 0, c = C - 1;
    while (r < R || c >= 0)
    {
        if (key == arr[r][c])
        {
            cout << r << " " << c << endl;
            return;
        }
        else if (arr[r][c] > key)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
}
int main()
{
    int arr[R][C] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    search(arr, 29);
    return 0;
}